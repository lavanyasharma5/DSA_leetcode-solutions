/*
problem: 876. Middle of the Linked List
link: https://leetcode.com/problems/middle-of-the-linked-list/
difficulty: easy

Description:
Given the head of a singly linked list, return the middle node of the linked list.
If the linked list has an odd number of nodes, return the exact middle node.
If the linked list has an even number of nodes, there will be two middle nodes.
Return the second middle node.

Approach:
1. Initialize two pointers:
   - slow moves one node at a time.
   - fast moves two nodes at a time.
2. Traverse the list while fast and fast->next are not nullptr.
3. Move:
   - slow = slow->next
   - fast = fast->next->next
4. When fast reaches the end of the list (or moves past it),
   slow will be pointing to the middle node.
5. Return slow.

Why it works:
- Fast moves twice as quickly as slow.
- By the time fast reaches the end, slow has covered only half the distance,
  so it naturally points to the middle.
- For even-length lists, slow lands on the second middle node as required.

Time: O(n)
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

class Solution{
    public:
    ListNode* middleNode(ListNode* head){
        if(head == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow= slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};