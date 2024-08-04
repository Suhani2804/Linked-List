//important for interviews
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){ //constructor
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val){//head by reference because we are modifying the linked list
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){ 
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head; //n now points to first node
    head=n; //n becomes first node
}

bool search(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}


void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}

void deletion(node* &head,int val){
    if(head==NULL){//no element in linked list so we can delete anything
        return;
    }
    if(head->next==NULL){//only one element in ll
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){ //traverse the list till n-1 nodes
        temp=temp->next;
    }
    node* todelete=temp->next;//the n-1>next contains the address of n node that is to be deleted
    temp->next=temp->next->next;//point n-1 node to n+1 node
    delete todelete;
}


node* reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;//introduce nextptr to next of currptr
        currptr->next=prevptr;//reversing
        prevptr=currptr;//moving forward
        currptr=nextptr;//moving forward
    }
    return prevptr;//prevptr will be the new head of the linked list
}

node* reverseRecursive(node* &head)
{
    //time complexity: o(n)
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

node* reversek(node* &head,int k){
    //time complexity: o(n)
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;
    //to reverse first k nodes
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    //to reverse further nodes from k+1
    if(nextptr!=NULL){
        head->next=reversek(nextptr,k);
    }
    return prevptr;//prevptr is the new head
    
}

int length(node* head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        l++;
    }
    return l;
}

node* kappend(node* &head,int k){
    node* newHead;
    node* newTail;
    node* tail=head;
    int l=length(head);
    k=k%l;
    int count=1;
    while(tail->next!=NULL){
        if(count==l-k){
            newTail=tail;
        }
        if(count==l-k+1){
            newHead=tail;
        }
        tail=tail->next;
        count++;
    }   
    newTail->next=NULL;
    tail->next=head;
    return newHead;
}

void intersect(node* &head1,node* &head2,int pos){
    node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

int intersection(node* &head1,node* &head2){
    int l1=length(head1);
    int l2=length(head2);
    int d=0;
    node* ptr1;
    node* ptr2;
    //assume that ptr1 will always pt at head of longer linked list
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
       ptr1= ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

node* merge(node* &head1,node* &head2){
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(-1);
    node* p3=dummyNode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
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

node* mergeRecursive(node* &head1,node* &head2){
    node* result;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }
    return result;
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
    // cout<<intersection(head1,head2);

    // node* newhead=merge(head1,head2);
    // display(newhead);
    node* newhead=mergeRecursive(head1,head2);
    display(newhead);
    return 0;
}