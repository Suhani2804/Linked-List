#include<iostream>
using namespace std;

class Node{
    public:
    Node* next;
    int val;
    Node(int x)
    {
        next=NULL;
        val=x;
    }
};

class Circular{
    public:
    Node* head;
    Circular():head(NULL){}

    int totsum()
    {
        if(head==NULL) return 0;
        int sum=0;
        Node* temp=head;
        do
        {
            sum+=temp->val;
            temp=temp->next;
        }while(temp!=head);
        return sum;
    }

    void createlist()
    {
        int totalsum=totsum();
        if(head==NULL) return ;
        Node* temp=head;
        do{
            temp->val=totalsum-temp->val;
            temp=temp->next;
        }while(temp!=head);
        return ;
    }

    int digitSum(int num)
    {
        int sum=0;
        while(num>0)
        {
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }

    Node* removeEven()
    {
        Node* current=head;
        do
        {
            Node* nextnode=current->next;
            if(digitSum(current->val)%2==0)
            {
                removenode(current);
            }
            current=nextnode;
        }while(current!=head);
    }

    Node* removenode(Node* current)
    {
        if(current==NULL) return NULL;
       if (current == head) // First node to be deleted
        {
            if (head->next == head) // Only one node in the list
            {
                delete head;
                head = NULL;
            }
            else
            {
                Node* temp = head;
                while (temp->next != head) // Find the last node
                {
                    temp = temp->next;
                }
                head = head->next;
                temp->next = head;
                delete current;
            }
        }
        delete current;
    }

    void printList() {
       if (head == NULL) return;
        Node* current = head;
        do {
        cout << current->val << " ";
        current = current->next;
        } while (current != head);
        cout << endl;
    }

    void insert(int val)
    {
        Node* newnode= new Node(val);
        if(head==NULL)
        {
            head=newnode;
            newnode->next=head;
        }
        else{
            Node* temp=head;
            do
            {
                temp=temp->next;
            }while(temp->next!=head);
            temp->next=newnode;
            newnode->next=head;
        }
    }


};

int main()
{
    Circular list;
    int n, value;

    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter value for node " << (i + 1) << ": ";
        cin >> value;
        list.insert(value);
    }

    cout << "Original list:" << endl;
    list.printList();

    list.removeEven();
    cout << "Modified list:" << endl;
    list.printList();

    return 0;
}
 