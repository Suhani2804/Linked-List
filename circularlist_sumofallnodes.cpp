#include<iostream>
#include<vector>
using namespace std;

class Node{
   public:
   int data;
   Node* next;

   Node(int x)
   {
        next=NULL;
        data=x;
   }
};

class circularList{
    public:
   Node* circularlist(vector<int> &values)
   {
      if(values.empty()) return NULL;
      Node* head=new Node(values[0]);
      Node* current=head;
      for(int i=1;i<values.size();i++)
      {
        current->next=new Node(values[i]);
        current=current->next;
      }
      current->next=head;
      return head;
   }

   int totalSum(Node* head)
   {
        if(head==NULL ) return 0;
        int totsum=0;
        Node* temp=head;
        do{
            totsum+=temp->data;
            temp=temp->next;
        }while(temp!=head);
        return totsum;
   }

   Node* createspecialcircularlinkedlist(Node* head,int totsum){
        if(head==NULL) return NULL;
        Node* current=head;
        do{
            current->data=totsum-current->data;
            current=current->next;
        }while(current!=head);
        return head;
   }

    void printCircularList(Node* head) {
        if (head == NULL) return;
        Node* current = head;
        do {
        cout << current->data << " ";
        current = current->next;
        } while (current != head);

        cout << endl;
    }

};
int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    if (n <= 0) {
    cout << "The number of nodes must be positive." << endl;
    return 1;
    }
    vector<int> values(n);
    cout << "Enter the values for the nodes: ";
    for (int i = 0; i < n; ++i) {
    cin >> values[i];
    }
    circularList n2;
    Node* head = n2.circularlist(values);
    int totalSum = n2.totalSum(head);
    head=n2.createspecialcircularlinkedlist(head, totalSum);
    cout << "Modified circular linked list: ";
    n2.printCircularList(head);
    return 0;
}