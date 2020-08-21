Node* reverse(Node* head){
    Node* curr=head,*prev=NULL,*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}
void reorderList(Node* head) {
    Node* slow=head,*fast=head;
    Node* prev=NULL;
    
    if(head->next==NULL || head->next->next==NULL){
        return;
    }
    /*  
        1 7 3 4 
        p   s     f
    */
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        prev=slow;
        slow=slow->next;
    }
    prev->next=NULL;
    Node* head1=reverse(slow);
    Node* next1=NULL,*next2=NULL;
    while(head!=NULL && head1!=NULL){
        next1=head->next;
        next2=head1->next;
        head->next=head1;
        if(next1)
            head1->next=next1;
        head=next1;
        head1=next2;
    }
    
}
/*
       
    1->2
    5->4->3
    
    
    
    1->7 
    4->3
    
    
    
    its reorder is 1->5->2->4->3.
    
            next
    1->     2->     5->     4->     3
    head            slow     
    
    1 7 3 4
    
    1 7 4 3
    t1
    
    
    temp=head->next;
    temp1=slow->next
    head->next=slow;
    slow->next=temp;
    head=temp;
    slow=temp1;
    
    
*/
