//step1
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode();
        ListNode *ansHead = ans;
        int carry = 0;
        while(l1 || l2){
            int sum;
            if(l1 && l2){
                sum = carry + l1->val + l2->val;
                ans->val = sum % 10;
                carry = sum / 10;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1 && !l2){
                sum = carry + l1->val;
                ans->val = sum % 10;
                carry = sum / 10;
                l1 = l1->next;
            }else if(!l1 && l2){
                sum = carry + l2->val;
                ans->val = sum % 10;
                carry = sum / 10;
                l2 = l2->next;
            }
            if(l1 || l2){
                ans->next = new ListNode();
                ans = ans->next;
            }
        }
        if(carry){
            ans->next = new ListNode(1);
        }
        return ansHead;
    }
};

//step2, step3
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode();
        ListNode *ansHead = ans;
        int carry = 0;
        while(l1 || l2){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            ans->val = sum % 10;
            carry = sum / 10;
            if(l1 || l2){
                ans->next = new ListNode();
                ans = ans->next;
            }else if(carry){
                ans->next = new ListNode(1);
            }
        }
        return ansHead;
    }
};

