/*
problem: 2095. Delete the Middle Node of a Linked List
link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
difficulty: medium

Description:
Given the head of a singly linked list, delete the middle node
and return the head of the modified linked list.

The middle node is located at index floor(n / 2),
where n is the number of nodes in the list.

Examples:
n = 1 -> delete index 0
n = 2 -> delete index 1
n = 3 -> delete index 1
n = 4 -> delete index 2
n = 5 -> delete index 2

Approach (Slow & Fast Pointer):
1. If the list contains only one node,
   deleting the middle node makes the list empty.
   Return nullptr.

2. Use three pointers:
   - slow : moves one step at a time.
   - fast : moves two steps at a time.
   - prev : stores the node before slow.

3. Traverse the list:
   - Move prev to slow.
   - Move slow one step.
   - Move fast two steps.

4. When fast reaches the end,
   slow will be pointing to the middle node.

5. Delete the middle node by connecting:
      prev->next = slow->next

6. Return the original head.

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
    ListNode* deleteMiddle(ListNode* head){

        //if the list is empty OR only contans one node(delete that node) return null
        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow= head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;

        return head;
    }
};