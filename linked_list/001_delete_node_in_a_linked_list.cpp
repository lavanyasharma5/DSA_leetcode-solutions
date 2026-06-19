/*
problem: 237. Delete Node in a Linked List
link: https://leetcode.com/problems/delete-node-in-a-linked-list/
difficulty: medium

Description:
Given a node in a singly linked list, delete it.

You are NOT given the head of the list.
It is guaranteed that the given node is not the last node.

Approach:
1. Copy the value of the next node into the current node.
2. Store the next node in a temporary pointer.
3. Skip the next node by updating links.
4. Delete the stored node.
5. The current node now effectively becomes the next node.

Example:
4 -> 5 -> 1 -> 9
Given node = 5
Copy 1 into 5:
4 -> 1 -> 1 -> 9
Skip the second 1:
4 -> 1 -> 9

Time: O(1)
Space: O(1)
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;

        ListNode* temp = node->next;
        node->next = node->next->next;

        delete temp;
    }
};