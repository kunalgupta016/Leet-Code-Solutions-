/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Function to get the length of the linked list
    int getLength(ListNode* head) {
        int cnt = 0;
        while (head != NULL) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    // Function to delete the middle node
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: If the list has only one node, return NULL
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        int len = getLength(head); // Get the length of the list
        int middle = len / 2; // Find the middle position
        ListNode* temp = head; // Start from the head of the list
        
        // Traverse to the node just before the middle node
        for (int i = 1; i < middle; i++) {
            temp = temp->next;
        }
        
        // Now temp is just before the middle node
        ListNode* toDelete = temp->next; // The middle node to delete
        temp->next = toDelete->next; // Bypass the middle node
        delete toDelete; // Free memory for the middle node

        return head;
    }
};
