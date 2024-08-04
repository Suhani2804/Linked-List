//even position elements afterwards in a linked list and odd position elements befor in a linked list
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

void evenAfterOdd(node* &head){
    node* odd=head;
    node* even=head->next;
    node* evenstart=even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenstart;
    if(odd->next!=NULL){
        even->next==NULL;
    }
}

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

void display(node* head){//head not by reference because we are just printing the array
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head=NULL;
    int arr[]={1,2,3,4,5,6};
    //expected linked list: 1,3,5,2,4,6
    for (int i = 0; i < 6; i++)
    {
        insertAtTail(head,arr[i]);
    }
    display(head);
    evenAfterOdd(head);
    display(head);
    
}