/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(1){
            if(!(fast && fast->next)) return NULL;
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        while(head != slow){
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};
