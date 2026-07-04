/*
    Problem: 138. Copy List with Random Pointer
    Link: https://leetcode.com/problems/copy-list-with-random-pointer/
    Difficulty: Medium

    Description:
    Given the head of a linked list where each node contains an
    additional random pointer that can point to any node in the list
    or null, create a deep copy of the entire linked list. The copied
    list should contain new nodes with the same values, next pointers,
    and random pointer connections as the original list.

    Approach:
    1. Traverse the original list and insert a copy node immediately
       after each original node.
    2. Traverse the modified list again and assign the random pointers
       of the copied nodes using:
           copyNode->random = originalNode->random->next
       since every copied node is placed directly after its original.
    3. Traverse once more to separate the interleaved list into the
       original list and the deep copied list while restoring the
       original list structure.
    4. Return the head of the copied linked list.

    Why it works:
    - Placing each copied node immediately after its original allows
      direct access to the copied version of any node without using
      a HashMap.
    - Random pointers are correctly assigned in O(1) time using the
      original node's random pointer.
    - Finally, both lists are detached, producing the required deep
      copy while restoring the original list.

    Time: O(N)
    Space: O(1) Auxiliary Space
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:

    // Step 1: Insert copy node after every original node
    void insertCopyInBetween(Node* head) {
        Node* temp = head;

        while (temp != nullptr) {

            Node* nextNode = temp->next;

            Node* copy = new Node(temp->val);

            temp->next = copy;
            copy->next = nextNode;

            temp = nextNode;
        }
    }

    // Step 2: Connect random pointers of copied nodes
    void connectRandomPointers(Node* head) {
        Node* temp = head;

        while (temp != nullptr) {
            Node* copyNode = temp->next;

            if (temp->random != nullptr)
                copyNode->random = temp->random->next;
            else
                copyNode->random = nullptr;

            temp = temp->next->next;
        }
    }

    // Step 3: Separate original list and copied list
    Node* getDeepCopyList(Node* head) {
        Node* temp = head;

        Node* dummy = new Node(-1);
        Node* res = dummy;

        while (temp != nullptr) {

            // Add copied node to copied list
            res->next = temp->next;
            res = res->next;

            // Restore original list
            temp->next = temp->next->next;

            temp = temp->next;
        }
        return dummy->next;
    }

    Node* copyRandomList(Node* head) {

        if (head == nullptr)
            return nullptr;

        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};