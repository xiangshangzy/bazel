#include "json/json.h"
#include <iostream>
#include <fstream>
int main(int argc, char const *argv[])
{
    std::ifstream config_doc("D:/tmp/language.json", std::ifstream::binary);
    Json::Value root;
    config_doc >> root;
    std::string my_encoding = root.get("my-encoding", "UTF-error").asString();
    std::cout << my_encoding << std::endl;
    return 0;
}
