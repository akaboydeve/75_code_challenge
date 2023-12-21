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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ptr1 = list1;
        ListNode *ptr2 = list2;
        ListNode *result = NULL;
        ListNode *current = NULL;

        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        if ((ptr1->val) < (ptr2->val))
        {
            result = new ListNode(ptr1->val);
            ptr1 = ptr1->next;
        }
        else
        {
            result = new ListNode(ptr2->val);
            ptr2 = ptr2->next;
        }

        current = result;

        while (ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr1->val < ptr2->val)
            {
                current->next = new ListNode(ptr1->val);
                ptr1 = ptr1->next;
            }
            else
            {
                current->next = new ListNode(ptr2->val);
                ptr2 = ptr2->next;
            }
            current = current->next;
        }

        while (ptr1 != NULL)
        {
            current->next = new ListNode(ptr1->val);
            ptr1 = ptr1->next;
            current = current->next;
        }

        while (ptr2 != NULL)
        {
            current->next = new ListNode(ptr2->val);
            ptr2 = ptr2->next;
            current = current->next;
        }

        return result;
    }
};
