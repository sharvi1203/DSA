/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        flattenTail(head);
        return head;
    }
    Node* flattenTail(Node* head){
        if(head==NULL)  return NULL;
        if(head->child==NULL){
            if(head->next==NULL)    return head;
            return flattenTail(head->next);
        }else{
            Node* next=head->next;
            Node* child=head->child;
            head->child=NULL;
            Node* childTail=flattenTail(child);
            head->next=child;
            child->prev=head;
            if(next!=NULL){
                childTail->next=next;
                next->prev=childTail;
                return flattenTail(next);
            }
            return childTail;
        }
        
    }
};
