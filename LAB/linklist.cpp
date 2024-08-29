//simple program for undersatnding link list
#include <iostream>
using namespace std;

class Node {

public:
    int data;
    Node* link;

    Node(int data) {
        this->data = data;
        this->link = NULL;
    }
};

class LinkedList {

public:
    Node* head;

    LinkedList() {
        this->head = NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    return 0;
}
