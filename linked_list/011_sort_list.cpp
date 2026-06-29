/*
Problem: 148. Sort List
Link: https://leetcode.com/problems/sort-list/
Difficulty: Medium

Description:
Given the head of a singly linked list, sort the linked list
in ascending order and return its head.

Approach (Merge Sort):
1. Handle the base case (empty list or single node).
2. Find the middle of the linked list using slow and fast pointers.
3. Split the list into two halves.
4. Recursively sort both halves using merge sort.
5. Merge the two sorted halves using the merge-two-sorted-lists technique.
6. Return the head of the merged sorted list.

Why it works:
- Merge Sort follows the Divide and Conquer approach.
- Each recursive call splits the list into smaller halves until
  each list contains only one node (already sorted).
- The sorted halves are merged while maintaining sorted order.
- This guarantees the final linked list is completely sorted.

Time: O(n log n)
Space: O(log n)   // Recursion stack
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
    //function to find the middle node
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next; //to reach the first middle node in even lists 

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    //merge two sorted linked lists 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1= list1;
        ListNode* t2= list2;
        ListNode* dummy= new ListNode(-1);
        ListNode* temp = dummy;

        while(t1 != nullptr && t2 != nullptr){
            if (t1->val < t2->val) {
                temp->next = t1;   // attach node from list1
                temp = t1;         // move temp
                t1 = t1->next;     // move list1
            }
            else {
                temp->next = t2;   // attach node from list2
                temp = t2;         // move temp
                t2 = t2->next;     // move list2
            }
        }
        // Attach remaining nodes
        if (t1 != nullptr)
            temp->next = t1;
        else
            temp->next = t2;

        // Skip dummy node
        return dummy->next;
    }
    //merge sort for LL function
    ListNode* sortList(ListNode* head) {
        //base case
        if(head == nullptr || head->next == nullptr) return head;

        //find middle
        ListNode* middleNode = middle(head);

        //split list 
        ListNode* left= head;
        ListNode* right = middleNode->next;
        middleNode->next = nullptr;

        //split and sort both halves
        left = sortList(left);
        right = sortList(right);

        //merge sorted halves
        return mergeTwoLists(left, right);
    }
};