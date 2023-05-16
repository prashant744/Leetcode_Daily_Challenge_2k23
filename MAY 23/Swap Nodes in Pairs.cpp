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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* tempHead=head;
        ListNode* temp=tempHead->next;

        tempHead->next=tempHead->next->next;
        temp->next=tempHead;
        tempHead->next=swapPairs(tempHead->next);
        return temp;
    }
};