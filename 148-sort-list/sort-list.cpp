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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast= head;
        ListNode* temp = nullptr;
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;
        ListNode* ll1 = sortList(head);
        ListNode* ll2 = sortList(slow);

        return mergeList(ll1,ll2);

    }
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode* ptr = new ListNode(0);
        ListNode* curr = ptr;

        while(l1 && l2){
            if(l1->val<l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1){
            curr->next = l1;
            l1 = l1->next;
        }
        if(l2){
            curr->next = l2;
            l2 = l2->next;
        }
        return ptr->next;
    }
};