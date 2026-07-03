/*
    Problem: 61. Rotate List
    Link: https://leetcode.com/problems/rotate-list/
    Difficulty: Medium

    Description:
    Given the head of a singly linked list, rotate the list to the right
    by k places and return the new head.

    Approach:
    1. Handle edge cases (empty list, single node, or k = 0).
    2. Traverse the list once to find its length and the tail node.
    3. Reduce unnecessary rotations using k %= length.
    4. Connect the tail to the head to form a circular linked list.
    5. Find the new last node at position (length - k).
    6. Set the node after it as the new head.
    7. Break the circular link to obtain the rotated list.

    Why it works:
    - Rotating right by k means the last k nodes become the new prefix.
    - Forming a circular list avoids repeatedly moving nodes.
    - Cutting the circle after the (length - k)th node produces the
      required rotated linked list.

    Time: O(N)
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

class Solution {
public:
    ListNode* findnthnode(ListNode* head, int n){
        ListNode* temp = head;
        n--;
        while(temp != nullptr && n>0){
            temp = temp->next;
            n--;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k==0) return head;

        ListNode* tail = head;
        int len=1;
        //find the length of the list and the last node of the list
        while(tail->next != nullptr){
            len++;
            tail = tail->next;
        }

        k %= len;
        if(k==0) return head;

        //make the list circular
        tail->next = head;
        //find the new last node
        ListNode* newLastNode = findnthnode(head, len-k);
        //the new head will be the node after the new last node
        head = newLastNode->next;
        //break teh circle as new last node --> next == null
        newLastNode->next = nullptr;

        return head;
    }
};