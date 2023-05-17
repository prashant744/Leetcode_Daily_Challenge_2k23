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
    ListNode* x;
    void helper(ListNode* p,int &res){
        if(p==NULL)return;
        helper(p->next,res);
        res=max(res,p->val+x->val);
        x=x->next;
    }

    int pairSum(ListNode* head) {
        ListNode* p=head;
        ListNode* q=head;

        x=head;
        int res=0;
        while(p && p->next){
            p=p->next->next;
            q=q->next;
        }
        helper(q,res);
        return res;
    }
};