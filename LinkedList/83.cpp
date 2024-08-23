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
        while(current){
            while(current->next && current->val == current->next->val){
                current->next = current->next->next;
            }
            current = current->next;
        }
        return head;
    }
};

//========================================================================

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
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *current = dummyHead;
        while(current->next && current->next->next){
            if(current->next->val != current->next->next->val){
                current = current->next;
                continue;
            }
            ListNode *duplicateNode = current->next;
            while(duplicateNode->next && duplicateNode->val == duplicateNode->next->val){
                duplicateNode = duplicateNode->next;
            }
            current->next = duplicateNode->next;
        }
        return dummyHead->next;
    }
};
