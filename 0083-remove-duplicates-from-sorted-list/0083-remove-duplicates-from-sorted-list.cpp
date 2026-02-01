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
        set<int> s;
        while(head!=NULL){
            s.insert(head->val);
            head=head->next;
        }
        ListNode* temp=new ListNode(0);
        head=temp;
        for (auto x : s){
            cout<<x<<" ";
            ListNode* temp1=new ListNode(x);
            temp->next=temp1;
            temp=temp->next;
        }

        return head->next;
    }
};