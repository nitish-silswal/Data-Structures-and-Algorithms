//----------- _/\_--- NITISH SILSWAL---_/\_------
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int height;
    Node *left , *right;

    Node(int x)
    {
        data = x;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int height(Node* root)
{
    if(root == NULL)    
        return 0;
    
    return root->height;
}

int getBalanceFactor(Node* root)
{
    if(root == NULL)
        return 0;
    
    return (height(root->left) - height(root->right));
}

void rightRotate(Node* &root)
{
    Node* l = root->left;
    Node* r = root->right;

    l->right = root;
    root->left = r;
    
    Node* prevRoot = root;
    root = l;
    l->height = max(height(root->left) , height(root->right));
    prevRoot->height = max(height(prevRoot->left) , height(prevRoot->right));
    
}

void leftRotate(Node* &root)
{
    Node* r = root->right;
    Node* l = root->right->left;
   
    root->right = l;
    r->left = root;
    
    Node* prevRoot = root;
    root  = r;

    root->height = max(height(root->left), height(root->right));
    prevRoot->height = max(height(prevRoot->left) , height(prevRoot->right));

}

void insert(Node* &root , int x)
{
    if(root == NULL)
    {
        root = new Node(x);
        return ;
    }

    if(x < root->data)
        insert(root->left , x);
    
    if(x > root->data)
        insert(root->right , x);
}

void printInorder(Node* root)
{
    if(root == NULL)
        return ;
    
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(void)
{
    Node* root  = new Node(8);
    root->left = new Node(6);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->right = new Node(10);

    

    printInorder(root);
    cout<<"\n";    


    return 0;
}