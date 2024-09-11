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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto *t=head;
        while(head!=NULL){
            if(head->next){
                int n=gcd(head->val,head->next->val);
                ListNode *node=new ListNode(n);
                auto *temp=head->next;
                head->next=node;
                node->next=temp;
                head=head->next;
            }
            head=head->next;
            
        }
        return t;
    }
};