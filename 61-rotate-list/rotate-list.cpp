class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* end = nullptr;
        ListNode* temp = head;
        int size = 0;

        while (temp) {
            if (temp->next == nullptr)
                end = temp;

            size++;
            temp = temp->next;
        }

        k %= size;

        // if (k == 0)
        //     return head;

        temp = head;

        int times = size - k - 1;

        while (times--) {
            temp = temp->next;
        }

        end->next = head;
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};