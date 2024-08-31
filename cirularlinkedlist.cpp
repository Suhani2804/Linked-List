#include <iostream>
using namespace std;

class Node{
    public:
    Node* next;
    int data;
    Node(int x)
    {
        next=NULL;
        data=x;
    }
    
    Node* insertInEmptyList(Node* last, int x)
    {
        Node* newnode=new Node(x);
        if(last!=NULL) return last;
        
        newnode->next=newnode;
        last=newnode;
        return last;
    }
    
    Node* insertEnd(Node* last,int x)
    {
        Node* newnode=new Node(x);
        if(last==NULL){
            last=newnode;
            newnode->next=newnode;
            return last;
        }
        newnode->next=last->next;
        last->next=newnode;
        last=newnode;
        return last;
    }
    
    Node* insertAtBegin(Node* last,int x)
    {
        Node* newnode=new Node(x);
        if(last==NULL)
        {
            last=newnode;
            newnode->next=newnode;
            return last;
        }
        newnode->next=last->next;
        last->next=newnode;
       return last;
    }
    
    Node* insertAtPosition(Node* last,int x,int pos)
    {
        if (last == NULL) {
            if (pos != 1) {
                cout << "Invalid position" << endl;
                return last;
            }
            Node* newnode = new Node(x);
            last = newnode;
            newnode->next = newnode;
            return last;
        }
        
        Node* newnode = new Node(x);
        Node* curr = last->next;
        
        if (pos == 1) {
            newnode->next = curr;
            last->next = newnode;
            return last;
        }
        
        for (int i = 1; i < pos - 1; i++) {
            curr = curr->next;
            if (curr == last) {
                cout << "Invalid position" << endl;
                delete newnode;
                return last;
            }
        }
        
        newnode->next = curr->next;
        curr->next = newnode;
        if (curr == last) {
            last = newnode;
        }
        return last;
    }
    
    Node* deleteFirstNode(Node* last) 
    {
        if(last==NULL)
        {
            return last;
        }
        Node* head=last->next;
        if(head->next==NULL)
        {
            delete(head);
            last=NULL;
            return last;
        }
        last->next=head->next;
        delete(head);
        return last;
    }
    
    Node* deleteSpecificNode(Node* last, int pos)
    {
        if (last == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return NULL;
        }

        Node* curr = last->next;
        Node* prev = last;
        
        //only one node in ll
        if(curr==last && curr->data==pos)
        {
            delete(curr);
            last=NULL;
            return last;
        }
        
        //node to be deleted is as the starting
        if(curr->data==pos)
        {
            last->next=curr->next;
            delete(curr);
            return last;
        }
        
        //travel till you find the node
        while(curr!=last && curr->data!=pos)
        {
            prev=curr;
            curr=curr->next;
        }
        
        //if the node is found
        if(curr->data==pos)
        {
            prev->next=curr->next;
            if(curr==last)
            {
                last=prev;
            }
            delete(curr);
            return last;
        }
        return last;
    }   
    
    Node* deleteLastNode(Node* last) {
        if (last == NULL) {
            cout << "List is empty, nothing to delete." << endl;
            return NULL;
        }
        Node* head = last->next;
        if(head==last)
        {
            delete(head);
            last=NULL;
            return last;
        }
        
        Node* curr=head;
        while(curr->next!=last)
        {
            curr=curr->next;
        }
        
        curr->next=head;
        delete(last);
        return curr;
    }
    
    void printList(Node* last) {
       if(last == NULL) return;
        Node *head = last->next;
        while (true){
            cout << head->data << " ";
            head = head->next;
            if (head == last->next) break;
        }
        cout << endl;
    }


};
int main() {
     Node node(0); // Node object to use methods

    Node* last = NULL;
    
    // Insert elements
    last = node.insertInEmptyList(last, 1);
    last = node.insertEnd(last, 2);
    last = node.insertEnd(last, 3);
    last = node.insertEnd(last, 4);
    cout << "List after inserts: ";
    node.printList(last);
    
    // Insert at position
    last = node.insertAtPosition(last, 5, 3);
    cout << "List after inserting 5 at position 3: ";
    node.printList(last);

    // Insert at the beginning
    last = node.insertAtBegin(last, 0);
    cout << "List after inserting 0 at the beginning: ";
    node.printList(last);
    
    // Delete specific node
    last = node.deleteSpecificNode(last, 2);
    cout << "List after deleting node with data 2: ";
    node.printList(last);
    
    // Delete first node
    last = node.deleteFirstNode(last);
    cout << "List after deleting the first node: ";
    node.printList(last);

    // Delete last node
    last = node.deleteLastNode(last);
    cout << "List after deleting the last node: ";
    node.printList(last);

    
    return 0;
}