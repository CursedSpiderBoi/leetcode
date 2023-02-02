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
        ListNode* temp=head;
        while(temp!=nullptr){
            if(temp->next && temp->val==temp->next->val){
                ListNode* dum=temp->next;
                temp->next=temp->next->next;
                delete dum;
                continue;
            }
            temp=temp->next;
        }
        return head;
    }
};
