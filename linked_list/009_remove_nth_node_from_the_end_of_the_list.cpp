/*
problem: 19. Remove Nth Node From End of List
link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
difficulty: Medium

Description:
Given the head of a singly linked list and an integer n,
remove the nth node from the end of the list and return
the head of the modified linked list.

Approach:
1. Initialize two pointers:
   - fast = head
   - slow = head
2. Move the fast pointer n steps ahead.
3. If fast becomes nullptr, the node to remove is the head.
4. Otherwise, move both pointers one step at a time until
   fast reaches the last node.
5. At this point, slow points to the node just before the
   node that needs to be deleted.
6. Update slow->next to skip the target node.
7. Delete the target node and return the head.

Why it works:
- The fast pointer always stays n nodes ahead of the slow pointer.
- When fast reaches the last node, slow is positioned just
  before the nth node from the end, allowing its removal
  in a single traversal.

Time: O(N)
Space: O(1)
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        //move fast ptr exactly n steps ahead
        //like giving a headstart to maintain a gap
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        //if fast becomes null, head is to be deleted
        if(fast == nullptr){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }
        //move both ptrs together
        while(fast->next != nullptr){
            slow= slow->next;
            fast = fast->next;
        }
        ListNode* delnode = slow->next;
        slow->next = delnode->next;
        delete delnode;

        return head;
    }
};