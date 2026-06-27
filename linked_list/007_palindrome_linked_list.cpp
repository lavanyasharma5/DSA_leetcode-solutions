/*
problem: 234. Palindrome Linked List
link: https://leetcode.com/problems/palindrome-linked-list/
difficulty: easy

Description:
Given the head of a singly linked list, determine whether
the linked list is a palindrome.
Return true if it reads the same forward and backward;
otherwise, return false.

Approach:
1. Find the end of the first half using slow and fast pointers.
2. Reverse the second half of the linked list.
3. Compare the first half and the reversed second half node by node.
4. If any pair of values differs, reverse the second half again
   to restore the original list and return false.
5. If all values match, restore the original list by reversing
   the second half again.
6. Return true.

Why it works:
- Reversing the second half lets us compare the list from both ends
  without using extra space.
- Restoring the reversed half ensures the original linked list
  remains unchanged after the function completes.

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
    ListNode* reverseLL(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next= prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next== nullptr) return true;

        ListNode *slow = head;
        ListNode *fast = head;

        while( fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseLL(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        while( second != NULL){
            if(first->val != second->val){
                reverseLL(slow->next);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(slow->next);
        return true;
    }
};