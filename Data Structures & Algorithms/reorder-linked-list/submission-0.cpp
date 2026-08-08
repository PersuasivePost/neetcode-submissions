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
    void reorderList(ListNode* head) {
        // find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        // reverse second part
        ListNode* prev = nullptr;
        ListNode* curr = second;

        while (curr != nullptr) {
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        
        second = prev;

        // join alternate
        ListNode* first = head;
        ListNode* third = prev;

        while (third != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = third->next;

            first->next = third;
            third->next = temp1;

            first = temp1;
            third = temp2;
        }   
    }
};
