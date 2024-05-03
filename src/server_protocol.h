#include <boost/asio.hpp>
#include <iostream>
#include <fstream>
#include <concurrent_quene.h>
using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::asio::ip;
class Conn : std::enable_shared_from_this<Conn>
{
public:
    Conn(tcp::socket &sock) : sock_(std::move(sock))
    {
        moodycamel::ConcurrentQueue<int> q(10);
        q.try_enqueue_bulk(10);
    }
    void Start()
    {
        do_read();
    }

private:
    tcp::socket sock_;
    enum
    {
        max_packet_len = 1024
    };
    char read_buffer[max_packet_len];

    void do_close()
    {
        sock_.close();
    }
    void do_read()
    {
        auto self(shared_from_this());
        sock_.async_read_some(
            buffer(read_buffer, max_packet_len),
            [this, self](boost::system::error_code err, size_t transferd)
            {
                if (err)
                {
                    do_close();
                    return;
                }
                do_read();
            });
    }
    void do_write()
    {
        auto self(shared_from_this());
        sock_.async_write_some(buffer(read_buffer, max_packet_len), [this, self](boost::system::error_code err, size_t transferd) {
         if(err)
         {
            do_close();
         }
         do_read();
        });
    }
};

class Server
{
public:
    Server(io_context &io_ctx, short port) : acceptor_(io_ctx, ip::tcp::endpoint(tcp::v4(), port)) {}
private:
    tcp::acceptor acceptor_;
    void do_accpet()
    {
        acceptor_.async_accept(
            [this](boost::system::error_code err, tcp::socket sock)
            {
                if (err)
                {
                }
                std::make_shared<Conn>(sock)->Start();
            });
    }
};