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
        if(head==NULL) return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* temp=dummy;
        while(head &&head->next){
            if(head->val!=head->next->val){
                temp->next=head;
                temp=head;
                head=head->next;
            }
            else{
                while(head->next&&(head->val==head->next->val)){
                    head=head->next;
                }
                head=head->next;
                temp->next=head;
            }
            
        }
        return dummy->next;
    }
    
};