#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_set>

using std::max;
using std::min;
using std::vector;
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *left = dummy;
        ListNode *right = dummy;

        for (int i = 0; i <= n; ++i)
        {
            right = right->next;
        }

        while (right)
        {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;

        head = dummy->next;
        delete dummy;

        return head;
    }
};
