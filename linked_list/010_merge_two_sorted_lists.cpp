/*
problem: 21. Merge Two Sorted Lists
link: https://leetcode.com/problems/merge-two-sorted-lists/
difficulty: easy

Description:
Given the heads of two sorted linked lists, merge them into
one sorted linked list and return its head.
The merged list should be formed by reusing the existing nodes.

Approach:
1. Create a dummy node and let temp point to it.
2. Traverse both lists while both are not nullptr.
3. Compare the current nodes of both lists.
   - Attach the smaller node to temp->next.
   - Move temp and the corresponding list pointer.
4. If one list finishes, attach the remaining nodes of
   the other list.
5. Return dummy->next (skip the dummy node).

Why it works:
- Both lists are already sorted.
- At every step, choosing the smaller node keeps the
  merged list sorted.
- The remaining nodes can be attached directly because
  they are already sorted.

Time: O(n + m)
Space: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1= list1;
        ListNode* t2= list2;
        ListNode* dummy= new ListNode(-1);
        ListNode* temp = dummy;

        while(t1 != nullptr && t2 != nullptr){
            if (t1->val < t2->val) {
                temp->next = t1;   // attach node from list1
                temp = t1;         // move temp
                t1 = t1->next;     // move list1
            }
            else {
                temp->next = t2;   // attach node from list2
                temp = t2;         // move temp
                t2 = t2->next;     // move list2
            }
        }
        // Attach remaining nodes
        if (t1 != nullptr)
            temp->next = t1;
        else
            temp->next = t2;

        // Skip dummy node
        return dummy->next;
    }
};