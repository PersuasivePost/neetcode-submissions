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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // find length of list
        int count = 0;
        ListNode* tempHead = head;
        while (tempHead != nullptr) {
            tempHead = tempHead->next;
            count++;
        }

        // removing the first node
        if (n == count) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* curr = head;

        int pos = 0;
        // reach nth node from end
        while (pos < count - n - 1) {
            curr = curr->next;
            pos++;
        }

        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;

        return head;
    }
};
