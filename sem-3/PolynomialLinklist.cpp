//simple program for undersatnding link list
#include <iostream>
using namespace std;

class Node {

public:
    int expo;
    int coff;
    Node* link;

    Node(int e,int c) {
        this->expo = e;
        this->coff = c;
        this->link = nullptr;
    }
};

class Polynomial {

public:
    Node* head;

    Polynomial() {
        this->head = NULL;
    }

    void insert(int e,int c) {
        Node* newNode = new Node(e,c);
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
            cout << "+" << temp->coff << "x^" << temp->expo; 
            temp = temp->link;
        }
        cout << endl;
    }
};

int main() {
    Polynomial* p1 = new Polynomial();

    p1->insert(3,3);
    p1->insert(2,2);
    p1->insert(1,1);
    p1->insert(0,1);


    p1->display();

}
