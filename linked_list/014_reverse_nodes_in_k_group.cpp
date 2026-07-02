/*
Problem: Reverse Nodes in K-Group
Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
Difficulty: Hard

Description:
Given the head of a singly linked list, reverse the nodes
of the list in groups of size k. If the remaining number of
nodes is less than k, leave them as they are.

Approach:
1. Traverse the linked list one group at a time.
2. Find the kth node from the current group's starting node.
3. If fewer than k nodes remain, leave the remaining nodes unchanged.
4. Detach the current group from the rest of the list.
5. Reverse the detached group using the standard linked list reversal.
6. Connect the reversed group with the previous reversed group.
7. Repeat the process for all complete groups.

Why it works:
- Each group is reversed independently.
- The previous group's tail is connected to the current group's new head.
- Incomplete groups are not modified, satisfying the problem constraints.

Time: O(N)
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
    // Returns the kth node starting from temp
    ListNode* getkthnode(ListNode* temp, int k) {
        k--; // temp is already the 1st node

        while (temp != nullptr && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }
    // Reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return nullptr;

        ListNode* temp= head;
        ListNode* prev= nullptr;

        while(temp != nullptr){
            //find teh kth node
            ListNode* kthnode= getkthnode(temp, k);

            //less than k nodes left 
            if(kthnode == nullptr){
                if(prev != nullptr) prev->next = temp;
                break;
            }
            // Store next group's start
            ListNode* nextNode = kthnode->next;

            // Disconnect current group
            kthnode->next = nullptr;

            // Reverse current group
            ListNode* newHead = reverseList(temp);

            // First group
            if (temp == head) {
                head = newHead;
            }
            else {
                prev->next = newHead;
            }
            // temp becomes last node after reversal
            prev = temp;

            // Move to next group
            temp = nextNode;
        }
        return head;
    }
};