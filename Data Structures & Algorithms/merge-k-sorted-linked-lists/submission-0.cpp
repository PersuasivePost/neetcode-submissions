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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;

        for (ListNode* head : lists) {
            ListNode* current = head;

            while (current != nullptr) {
                arr.push_back(current->val);
                current = current->next;
            }
        }
 
        sort(arr.begin(), arr.end());

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        for (int x : arr) {
            current->next = new ListNode(x);
            current = current->next;
        }

        return dummy->next;
    }
};
