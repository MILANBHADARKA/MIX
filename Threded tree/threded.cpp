#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    bool rightThread;
    
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
        rightThread = false;
    }
};

class threadtree
{
public:

    void insert(Node* root, int data){
        if(root == nullptr){
            root = new Node(data);
            return;
        }
        if(data < root->data){
            if(root->left == nullptr){
                root->left = new Node(data);
                root->left->right = root;
                root->left->rightThread = true;
            }
            else{
                insert(root->left, data);
            }
        }
        else{       //>=
            if(root->right == nullptr || root->rightThread){
                Node* temp = new Node(data);
                temp->right = root->right;
                root->right = temp;
                root->rightThread = false;
                temp->rightThread = true;
            }
            else{
                insert(root->right, data);
            }
        }
    }

    void inorder(Node* root){
        Node* temp = root;

        while(temp->left != nullptr){
            temp = temp->left;
        }

        while(temp != nullptr){
            cout << temp->data << " ";
            if(temp->rightThread){
                temp = temp->right;
            }
            else{
                temp = temp->right;
                while(temp->left != nullptr){
                    temp = temp->left;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    threadtree t;

    Node* root = nullptr;

    root = new Node(10);
    t.insert(root, 5);
    t.insert(root, 15);
    t.insert(root, 3);
    t.insert(root, 7);
    t.insert(root, 7);
    t.insert(root, 12);
    t.insert(root, 20);

    t.inorder(root);
    return 0;
}
