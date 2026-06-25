/*
problem: 206. Reverse Linked List
link: https://leetcode.com/problems/reverse-linked-list/
difficulty: easy

Description:
Given the head of a singly linked list, reverse the linked list and
return the new head of the reversed list.

Approach:
1. Initialize three pointers:
   - prev = nullptr
   - curr = head
   - front = nullptr
2. Traverse the linked list until curr becomes nullptr.
3. Store the next node using front = curr->next.
4. Reverse the current node's link:
   curr->next = prev.
5. Move both pointers one step ahead:
   - prev = curr
   - curr = front
6. When traversal finishes, prev points to the new head of the
   reversed linked list.
7. Return prev.

Time: O(n), where n is the number of nodes.
Space: O(1)
*/

#include <iostream>
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};