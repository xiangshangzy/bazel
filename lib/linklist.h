#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <math.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p = headA, *q = headB;
        if (p == nullptr || q == nullptr)
            return nullptr;
        while (p != q)
        {
            p = (p != nullptr ? p->next : headB);
            q = (q != nullptr ? q->next : headA);
        }
        return p;
    }

    ListNode *reverseList(ListNode *head)
    {

        ListNode *p = nullptr;
        for (ListNode *q = head, *r; q != nullptr; p = q, q = r)
        {
            r = q->next;
            q->next = p;
        }

        return p;
    }

    bool isPalindrome(ListNode *head)
    {
        string s = "";
        int n = 0;
        for (ListNode *p = head; p != nullptr; p = p->next)
        {
            s += p->val;
            n++;
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] != s[n - 1 - i])
                return false;
        }
        return true;
    }

    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> s;
        for (ListNode *p = head; p != nullptr; p = p->next)
        {
            if (s.find(p) != s.end())
                return true;
            s.insert(p);
        }
        return false;
    }

    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> s;
        for (ListNode *p = head; p != nullptr; p = p->next)
        {
            if (s.find(p) != s.end())
                return p;
            s.insert(p);
        }
        return nullptr;
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ans = new ListNode(0), *p = list1, *q = list2, *r = ans;
        while (p != nullptr && q != nullptr)
        {
            if (p->val < q->val)
            {
                r->next = p;
                p = p->next;
            }
            else
            {
                r->next = q;
                q = q->next;
            }
            r = r->next;
        }
        r->next = (p != nullptr ? p : q);
        return ans->next;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(0), *p = l1, *q = l2, *r = ans;
        int next = 0, sum;

        while (p != nullptr && q != nullptr)
        {
            sum = p->val + q->val + next;
            next = sum / 10;
            r->next = new ListNode(sum % 10);
            r = r->next;
            p = p->next;
            q = q->next;
        }
        while (p != nullptr)
        {
            sum = p->val + next;
            next = sum / 10;
            r->next = new ListNode(sum % 10);
            r = r->next;
            p = p->next;
        }
        while (q != nullptr)
        {
            sum = q->val + next;
            next = sum / 10;
            r->next = new ListNode(sum % 10);
            r = r->next;
            q = q->next;
        }
        if (next != 0)
            r->next = new ListNode(next % 10);
        return ans->next;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *ans = new ListNode(0), *p = ans, *q = head;
        p->next = head;
        for (int i = 0; i < n; i++)
        {
            q = q->next;
        }
        while (q != nullptr)
        {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return ans->next;
    }
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *ans = new ListNode(0), *p = ans, *q, *r;
        ans->next = head;
        while (p->next != nullptr && p->next->next != nullptr)
        {
            q = p->next;
            r = p->next->next;
            q->next = r->next;
            r->next = q;
            p->next = r;
            p = p->next->next;
        }
        return ans->next;
    }

    tuple<ListNode *, ListNode *> merge(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(0), *p = l1, *q = l2, *r = ans;
        while (p != nullptr && q != nullptr)
        {
            if (p->val < q->val)
            {
                r->next = new ListNode(p->val);
                p = p->next;
            }
            else
            {
                r->next = new ListNode(q->val);
                q = q->next;
            }
            r = r->next;
        }
        r->next = (p != nullptr ? p : q);
        while (r->next != nullptr)
        {
            r = r->next;
        }
        return {ans->next, r};
    }
    ListNode *sortList(ListNode *head)
    {
        ListNode *ans = new ListNode(0), *p = head;
        vector<ListNode *> v;
        while (p != nullptr)
        {
            v.push_back(p);
        }
        sort(v.begin(), v.end(), [](ListNode *a, ListNode *b)
             { return a->val < b->val; });
        p = ans;
        for (const auto &item : v)
        {
            p->next=item;
        }

        return ans->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *ans = nullptr;
        for (const auto &list : lists)
        {
            ans = mergeTwoLists(ans, list);
        }
        return ans;
    }
};