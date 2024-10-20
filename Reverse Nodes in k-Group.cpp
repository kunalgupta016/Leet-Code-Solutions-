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

   
    int getLength(ListNode* head) {
        int cnt = 0;
        while (head != NULL) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int len = getLength(head);
        if (len < k) {
            return head;
        }

     
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};
