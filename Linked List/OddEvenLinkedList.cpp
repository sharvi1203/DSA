// isme ulta hai isme hum index ke odd even lenge na ki node ki value ke
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* headOdd=NULL,*headEven=NULL,*tailOdd=NULL,*tailEven=NULL;
        headEven=head;
        tailEven=head;
        int count=1;
        head=head->next;
        while(head!=NULL){
            if(count%2==0){
                if(headEven){
                    tailEven->next=head;
                    tailEven=tailEven->next;
                }else{
                    headEven=head;
                    tailEven=head;
                }
            }else{
                if(headOdd){
                    tailOdd->next=head;
                    tailOdd=tailOdd->next;
                }else{
                    headOdd=head;
                    tailOdd=head;
                }
            }
            head=head->next;
            count++;
        }
        if(headOdd==NULL){
            return headEven;
        }
        tailOdd->next=NULL;
        tailEven->next=headOdd;
        return headEven;
    }
};
