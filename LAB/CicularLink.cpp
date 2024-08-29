#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int d;
    Node* next;

    Node(){
        next = nullptr;
    }
    Node(int x){
        d=x;
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
            start->next = start;
        }

        else{
            Node* temp = new Node();
            temp = start;

            while(temp->next != start){
                temp = temp->next;
            }
            temp->next = nn;
            nn->next = start;
        }

    }

    void Delete_end(){
        if(start == nullptr){
            cout << "Link is empty."<< endl;
        }
        else{
            Node* temp = new Node;
            temp = start;

            while(temp->next->next!=start){
                temp = temp->next;
            }
            temp->next = start;


        }
    }

    void display(){

        if(start == nullptr){
            cout << "Empty.";
        }

        else{
            Node* temp = new Node();
            temp = start;

            while(temp->next != start){
                cout << temp->d << endl;
                temp = temp->next;
            }
            cout << temp->d << endl;
        }
    }
};



int main(int argc, char const *argv[])
{
    impl* L1 = new impl();

    L1->insert_end(1);
    L1->insert_end(2);
    L1->insert_end(3);
    L1->insert_end(4);
    L1->insert_end(5);

    L1->Delete_end();

    L1->display();

    return 0;
}
