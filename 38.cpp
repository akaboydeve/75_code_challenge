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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty() || lists.size() == 0)
        {
            return nullptr;
        }

        while (lists.size() > 1)
        {
            vector<ListNode *> merged_lists;
            for (int i = 0; i < lists.size(); i += 2)
            {
                ListNode *l1 = lists[i];
                ListNode *l2 = (i + 1) < lists.size() ? lists[i + 1] : nullptr;
                merged_lists.push_back(mergeTwoLists(l1, l2));
            }
            lists = merged_lists;
        }

        return lists[0];
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }

            current = current->next;
        }

        current->next = l1 ? l1 : l2;

        return dummy->next;
    }
};