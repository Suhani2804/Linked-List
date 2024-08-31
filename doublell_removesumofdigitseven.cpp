#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int _val) : val(_val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}


    int digitSum(int num) {
        int sum = 0;
        // num = abs(num);
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    void removeNode(Node* nodeToRemove) {
        if (nodeToRemove == nullptr) return;
        if (nodeToRemove == head) {
            head = nodeToRemove->next;
        }
        if (nodeToRemove->next != nullptr) {
            nodeToRemove->next->prev = nodeToRemove->prev;
        }
        if (nodeToRemove->prev != nullptr) {
            nodeToRemove->prev->next = nodeToRemove->next;
        }
        delete nodeToRemove;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void removeEvenDigitSumNodes() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            if (digitSum(current->val) % 2 == 0) {
                removeNode(current);
            }
            current = nextNode;
        }
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->val << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList list;
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

    list.removeEvenDigitSumNodes();
    cout << "Modified list:" << endl;
    list.printList();

    return 0;
}
