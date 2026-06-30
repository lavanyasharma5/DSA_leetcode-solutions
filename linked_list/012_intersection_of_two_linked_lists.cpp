/*
Problem: 160. Intersection of Two Linked Lists
Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
Difficulty: Easy

Description:
Given the heads of two singly linked lists, return the node where the
two linked lists intersect. If the two lists do not intersect, return nullptr.

The intersection is determined by reference (same node), not by node value.
The original structure of the linked lists must remain unchanged.

Approach (Two Pointer Technique):
1. Initialize two pointers, t1 at headA and t2 at headB.
2. Traverse both lists simultaneously.
3. When a pointer reaches the end of its list, redirect it to the head
   of the other list.
4. Since both pointers traverse exactly (LengthA + LengthB) nodes,
   they become aligned automatically.
5. If the lists intersect, the pointers meet at the intersection node.
   Otherwise, both eventually become nullptr.

Why it works:
- Switching lists compensates for the difference in lengths.
- Both pointers travel the same total distance (A + B).
- They either meet at the first common node or both end at nullptr.

Time: O(N + M)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while( t1 != t2){
            //if t1 reaches null move it to headB else just move one step forward
            t1 = (t1 == nullptr) ? headB : t1->next;
            //if t2 reaches null move it to headA else just move one step forward
            t2 = (t2 == nullptr) ? headA : t2->next;
        }
        //will be either the intersection point or NULL(in case no intersection)
        return t1;
    }
};