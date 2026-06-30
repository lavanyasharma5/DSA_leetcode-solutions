/*
    Problem: 2. Add Two Numbers
    Link: https://leetcode.com/problems/add-two-numbers/
    Difficulty: Medium

    Description:
    Given the heads of two non-empty linked lists representing two
    non-negative integers, where each node stores a single digit in
    reverse order, add the two numbers and return the sum as a linked list.
    The result should also be stored in reverse order.

    Approach:
    1. Create a dummy node to simplify building the answer list.
    2. Traverse both linked lists simultaneously.
    3. At each step:
       - Add the current digits from both lists (if present).
       - Add the previous carry.
       - Create a new node with (sum % 10).
       - Update carry as (sum / 10).
    4. Continue until both lists are exhausted and carry becomes 0.
    5. Return dummy->next as the head of the resultant linked list.

    Why it works:
    - Digits are already stored in reverse order, so addition starts
      naturally from the least significant digit.
    - Carry is propagated exactly as in normal arithmetic addition.
    - The dummy node makes inserting new nodes simple without handling
      a special case for the first node.

    Time: O(max(N, M))
    Space: O(1) Auxiliary Space
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }
        return dummy->next;
    }
};