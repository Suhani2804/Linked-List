#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    int data;

    Node(int x) : next(nullptr), prev(nullptr), data(x) {}

    // Function to traverse the doubly linked list in forward direction
    void forwardTraversal(Node* head) {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Function to traverse the doubly linked list in backward direction
    void backwardTraversal(Node* tail) {
        Node* curr = tail;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << endl;
    }

    // Length of doubly linked list
    int findLength(Node* head) {
        int count = 0;
        Node* cur = head;
        while (cur) {
            count++;
            cur = cur->next;
        }
        return count;
    }

    void printList(Node* head) {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    Node* insertBegin(Node* head, int data) {
        Node* newnode = new Node(data);
        newnode->next = head;
        if (head != NULL) {
            head->prev = newnode;
        }
        return newnode;
    }

    Node* insertEnd(Node* head, int data) {
        Node* newnode = new Node(data);
        if (head == NULL) {
            return newnode;
        }
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newnode;
        newnode->prev = curr;
        return head;
    }

    Node* insertAtPosition(Node* head, int pos, int data) {
        if (head == NULL) {
            if (pos != 1) {
                cout << "Wrong" << endl;
                return head;
            }
            return new Node(data);
        }

        Node* newnode = new Node(data);

        // Insertion at the beginning
        if (pos == 1) {
            newnode->next = head;
            if (head != NULL)
                head->prev = newnode;
            return newnode;
        }

        Node* curr = head;
        for (int i = 1; i < pos - 1 && curr != NULL; ++i) {
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Position is out of bounds." << endl;
            delete newnode;
            return head;
        }

        newnode->next = curr->next;
        newnode->prev = curr;
        curr->next = newnode;

        if (newnode->next != NULL) {
            newnode->next->prev = newnode;
        }

        return head;
    }

    Node* delHead(Node* head) {
        if (head == NULL) return NULL;
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
        return head;
    }

    Node* delLast(Node* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) {
            delete head;
            return NULL;
        }
        Node* curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->prev->next = NULL;
        delete curr;
        return head;
    }

    Node* delPos(Node* head, int pos) {
        if (head == NULL) return head;
        Node* curr = head;
        for (int i = 1; curr && i < pos; ++i) {
            curr = curr->next;
        }

        if (curr == NULL) return head;
        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
        if (head == curr) head = head->next;
        delete curr;
        return head;
    }
};

int main() {
    Node node(0); // Node object to use methods

    Node* head = NULL;

    // Insert elements
    head = node.insertEnd(head, 1);
    head = node.insertEnd(head, 2);
    head = node.insertEnd(head, 3);
    head = node.insertEnd(head, 4);
    cout << "List after inserts: ";
    node.printList(head);

    // Insert at position
    head = node.insertAtPosition(head, 3, 5);
    cout << "List after inserting 5 at position 3: ";
    node.printList(head);

    // Insert at the beginning
    head = node.insertBegin(head, 0);
    cout << "List after inserting 0 at the beginning: ";
    node.printList(head);

    // Delete specific node
    head = node.delPos(head, 2); // 2 is the position of the node with data 1
    cout << "List after deleting node with data 2: ";
    node.printList(head);

    // Delete first node
    head = node.delHead(head);
    cout << "List after deleting the first node: ";
    node.printList(head);

    // Delete last node
    head = node.delLast(head);
    cout << "List after deleting the last node: ";
    node.printList(head);

    return 0;
}
