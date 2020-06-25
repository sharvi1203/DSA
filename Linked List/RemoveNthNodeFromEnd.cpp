//#################Two Pass############################### 
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
    int length(ListNode* head){
        int l=0;
        while(head!=NULL){
            head=head->next;
            l++;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=length(head);
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp=dummy;
        int pass=l-n;
        while(pass>0){
            pass--;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return dummy->next;
    }
};
//#################One Pass############################### 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return NULL;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* first=dummy,*second=dummy;
        for(int i=0;i<=n;i++){
            first=first->next;
        }
        while(first!=NULL){
            first=first->next;
            second=second->next;
        }
        second->next=second->next->next;
        return dummy->next;
    }
};
