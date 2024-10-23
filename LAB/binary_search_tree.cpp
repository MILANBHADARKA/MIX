//binary search tree
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void findmax(Node* root){
    if(root == NULL){
        cout << "Tree is empty" << endl;
        return;
    }
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    cout << "Max value is: " << temp->data << endl;
}

Node* insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;            
}

Node* insertuser(Node* root, Node* New){
    cout << "enter Choice for data" << " " << New->data << ": " <<endl;
    char ch;
    cin>>ch;

    if(ch == 'l'){
        if(root->left == NULL){
            root->left = New;
        }
        else{
            insertuser(root->left, New);
        }
    }
    else{
        if(root->right == NULL){
            root->right = New;
        }
        else{
            insertuser(root->right, New);
        }
    }
}

Node* invert(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* left = invert(root->left);
    Node* right = invert(root->right);

    root->left = right;
    root->right = left;

    return root;
}



void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//inorder traversal
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//postorder traversal
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    root = insert(root, 5);
    // insertuser(root, new Node(3));
    // insertuser(root, new Node(7));
    // insertuser(root, new Node(6));
    // insertuser(root, new Node(8));
    insert(root, 3);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);
    insert(root, 2);
    insert(root, 4);
    insert(root, 1);
    insert(root, 9);
    insert(root, 10);

    preorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    inorder(root);

    


    // preorder(root);

    // invert(root);


    // preorder(root);

    // findmax(root);
    

    return 0;
}

