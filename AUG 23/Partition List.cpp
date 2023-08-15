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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)return NULL;
        vector<int>vec;
        while(head!=NULL){
            vec.push_back(head->val);
            head=head->next;
        }
        vector<int>vec1;
        for(int i=0;i<vec.size();i++){
            if(vec[i]<x){
                vec1.push_back(vec[i]);
                vec.erase(vec.begin()+i);
                i--;
            }
        }
        reverse(vec.begin(),vec.end());
        for(int i=vec1.size()-1;i>=0;i--){
            vec.push_back(vec1[i]);
        }
        reverse(vec.begin(),vec.end());
        ListNode* root=NULL;
        for(int i=vec.size()-1;i>=0;i--){
            ListNode* temp=new ListNode;
            temp->val=vec[i];
            temp->next=root;
            root=temp;
        }
        return root;
    }
};