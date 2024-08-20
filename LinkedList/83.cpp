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
        ListNode *current = head;
        ListNode *search = head;
        while(current){
            search = search->next;
            while(search && current->val == search->val){
                search = search->next;
            }
            current->next = search;
            current = current->next;
        }
        return head;
    }
};
