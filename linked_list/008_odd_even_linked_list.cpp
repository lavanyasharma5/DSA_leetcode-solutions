/*
problem: 328. Odd Even Linked List
link: https://leetcode.com/problems/odd-even-linked-list/
difficulty: Medium

Description:
Given the head of a singly linked list, group all the nodes
at odd indices together followed by the nodes at even indices.
The relative order within the odd and even groups must remain
the same.

Approach:
1. Handle the edge case where the list has 0 or 1 node.
2. Initialize:
   - odd = head
   - even = head->next
   - evenHead = even (store the start of the even list)
3. Traverse while even and even->next are not nullptr:
   - Connect odd node to the next odd node.
   - Connect even node to the next even node.
   - Move both pointers one step forward.
4. After traversal, attach the even list after the odd list:
   - odd->next = evenHead.
5. Return the head of the modified list.

Why it works:
- Odd pointers skip over even nodes and link only odd-indexed nodes.
- Even pointers skip over odd nodes and link only even-indexed nodes.
- Since the order inside both groups is preserved, joining the two
  lists produces the required answer.

Time: O(N)
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
    ListNode* oddEvenList(ListNode* head) {
        if( head == nullptr || head->next == nullptr) return head;

        ListNode* odd= head;
        ListNode* even= head->next;
        ListNode* evenHead = even;

        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next= evenHead;
        return head;
    }
};