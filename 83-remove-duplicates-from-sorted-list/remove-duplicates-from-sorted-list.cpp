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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = head;
        while(node){
            ListNode* temp = node;
            int value = node->val;
            while(node->next && node->next->val == value){
                node = node->next;
            }
            node = node->next;
            temp->next = node;         
        }
        return head;
    }
};