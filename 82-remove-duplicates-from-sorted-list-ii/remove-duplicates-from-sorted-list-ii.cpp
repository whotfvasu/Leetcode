class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *left = head;
        ListNode *right = head;
        ListNode *prev = NULL;
        int occ = 0;

        while(right!=NULL){
            while(right!=NULL && left->val == right->val){
                right = right->next;
                occ++;
            }
            if(occ == 1){
                prev = left;
                
            }
            if(occ>1){
                if(prev==NULL) head = right;
                else prev->next = right;
            }
            left = right;
            occ = 0;

        }
        return head;
    }
};