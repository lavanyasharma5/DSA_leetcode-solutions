/*
Problem: 142. Linked List Cycle II
Link: https://leetcode.com/problems/linked-list-cycle-ii/
Difficulty: Medium

Description:
Given the head of a singly linked list, return the node where
the cycle begins. If there is no cycle, return nullptr.

Approach:
1. Initialize two pointers:
   - slow moves one node at a time.
   - fast moves two nodes at a time.
2. Traverse the list while fast and fast->next are not nullptr.
3. Move:
   - slow = slow->next
   - fast = fast->next->next
4. If slow and fast meet, a cycle exists.
5. Reset slow to head while keeping fast at the meeting point.
6. Move both pointers one step at a time.
7. The node where they meet again is the starting node of the cycle.
8. If fast reaches nullptr, no cycle exists, so return nullptr.

Why it works:
- The first meeting confirms that a cycle is present.
- Resetting one pointer to the head makes both pointers equally
  far from the starting node of the cycle.
- Moving both pointers one step at a time guarantees they meet
  exactly at the first node of the loop.

Time: O(n)
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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // this is our starting point
            }
        }
        return nullptr;
    }
};