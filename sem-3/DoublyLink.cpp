#include<bits/stdc++.h>
using namespace std;


class Node{
    public:

    Node* prev;
    int d;
    Node* next;

    Node(){
        d=0;
        prev = nullptr;
        next = nullptr;
    }

    Node(int x){
        d=x;
        prev = nullptr;
        next = nullptr;
    }
};

class impl{
    public:

    Node* start;

    impl(){
        start = nullptr;
    }

    void insert_end(int d){

        Node* nn = new Node(d);

        if(start == nullptr){
            start = nn;
        }

        else{
            Node* temp = new Node();
            temp = start;

            while(temp->next != nullptr){
                temp = temp->next;
            }
            nn->prev = temp;
            temp->next = nn;
        }

    }

    void Delete_end(){
        if(start == nullptr){
            cout << "Link is empty."<< endl;
        }
        else{
            Node* temp = new Node;
            temp = start;

            while(temp->next!=nullptr){
                temp = temp->next;
            }

            temp->prev->next = nullptr;

        }
    }

    void Insert_Before(int x, int y){
        if(start == nullptr){
            cout << "Link is empty."<< endl;
        }
        else{
            Node* temp = new Node;
            temp = start;

            while(temp->d != x){
                temp = temp->next;
            }

            Node* nn = new Node(y);
            nn->next = temp;
            nn->prev = temp->prev;
            temp->prev->next = nn;
            temp->prev = nn;

        }
    }

    void Insert_After(int x, int y){
        if(start == nullptr){
            cout << "Link is empty."<< endl;
        }
        else{
            Node* temp = new Node;
            temp = start;

            while(temp->d != x){
                temp = temp->next;
            }

            Node* nn = new Node(y);
            nn->prev = temp;
            nn->next = temp->next;
            temp->next = nn;
            temp->next->prev = nn;

        }
    }

    void display(){

        if(start == nullptr){
            cout << "Empty.";
        }

        else{
            Node* temp = new Node();
            temp = start;

            while(temp != nullptr){
                cout << temp->d << endl;
                temp = temp->next;
            }
        }
    }

};



int main(int argc, char const *argv[])
{
    impl* L1 = new impl();
    
    L1->insert_end(5);
    L1->insert_end(4);
    L1->insert_end(3);
    L1->insert_end(2);
    L1->insert_end(1);

    L1->Delete_end();
    L1->Insert_Before(3,6);
    L1->Insert_After(4,8);

    L1->display();


    return 0;
}
