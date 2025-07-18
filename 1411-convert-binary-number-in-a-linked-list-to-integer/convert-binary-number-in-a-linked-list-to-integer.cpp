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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        while(temp != NULL) {
            size++;
            temp = temp->next;
        }

        size = size - 1;

        temp = head;
        int number = 0;
        while(temp != NULL) {
            int value = temp->val;
            number += value * pow(2, size--);
            temp = temp->next;
        }
        return number;
    }
};