/*
problem: 141. Linked List Cycle
link: https://leetcode.com/problems/linked-list-cycle/
difficulty: easy

Description:
Given the head of a singly linked list, determine whether the linked
list contains a cycle.
A cycle exists if a node in the list can be reached again by
continuously following the next pointers.
Return true if there is a cycle; otherwise, return false.

Approach:
1. Initialize two pointers:
   - slow moves one node at a time.
   - fast moves two nodes at a time.
2. Traverse the list while fast and fast->next are not nullptr.
3. Move:
   - slow = slow->next
   - fast = fast->next->next
4. If slow and fast ever point to the same node, a cycle exists.
5. If fast reaches nullptr or fast->next becomes nullptr, the list
   has no cycle.
6. Return true if a cycle is found; otherwise, return false.

Why it works:
- If there is no cycle, the fast pointer reaches the end of the list.
- If there is a cycle, the faster pointer eventually catches up to the
  slower pointer inside the cycle.

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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        return false;
    }
};