        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummyNode->next;
}

void display(node* head){//head not by reference because we are just printing the array
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    // node* head=NULL;
    // insertAtTail(head,1);
    // insertAtTail(head,2);
    // insertAtTail(head,3);
    // insertAtTail(head,4);
    // display(head);

    // insertAtHead(head,5);
    // display(head);

    // cout<<search(head,2);

    // deleteAtHead(head);

    // node* newhead=reverseRecursive(head);
    // display(newhead);

    // int k=2;
    // node* newhead=reversek(head,k);
    // display(newhead);

    // display(head);
    // node* newHead=kappend(head,2);
    // display(newHead);

node* head1=NULL;
node* head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head2,0);
    insertAtTail(head2,-2);
    // intersect(head1,head2,3);
    // display(head1);
    // display(head2);