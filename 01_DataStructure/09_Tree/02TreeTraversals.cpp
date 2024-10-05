/*  *** BST : Basic Operations ***  

*   - Creation - AddNode()
*   - Insertion
*   - Deletion
*   - Find Element

*   - In Order Traversal        - InOrderTraversal()
*   - Pre Order Traversal       - PreOrderTraversal()
*   - Post Order Traversal      - PostOrderTraversal()
*   - Level Order Traversal     - LevelOrderTraversal()

*/
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};


void AddNode(Node** ioRoot, int iData){

    Node *newNode = new Node;
    newNode->data = iData;
    newNode->left = nullptr;
    newNode->right = nullptr;

    //add 1st/root Node in tree
    if(*ioRoot==nullptr){
        *ioRoot=newNode;
        return ;
    }

    Node *temp = *ioRoot, *lNode=nullptr;
    //go to last node where new node needs to be added
    while(temp){
        lNode = temp;
        if(temp->data>iData)
            temp=temp->left;
        else
            temp=temp->right;
    }

    //Add new node
    if(lNode->data>iData)
        lNode->left = newNode;
    else
        lNode->right = newNode;

}

void InOrderTraversal(Node* root){
    if(root ==nullptr)
        return ;

    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal(Node* root){
    if(root ==nullptr)
        return ;
    cout<<root->data<<" ";

    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root){
    if(root ==nullptr)
        return ;

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);

    cout<<root->data<<" ";
}

void LevelOrderTraversal(Node* root){
    if(root ==nullptr)
        return ;

    //TODO

}

int main(){
    Node *root = nullptr;

    AddNode(&root, 4);
    AddNode(&root, 2);
    AddNode(&root, 6);
    AddNode(&root, 1);
    AddNode(&root, 3);
    AddNode(&root, 5);
    AddNode(&root, 7);

    /*
            4
         /     \
        2       6
       / \     / \
      1   3   5   7

    InOrderTraversal : 1 2 3 4 5 6 7
    PreOrderTraversal : 4 2 1 3 6 5 7
    PostOrderTraversal : 1 3 2 5 7 6 4
    LevelOrderTraversal : 4 2 6 1 3 5 7
    */

    cout<<"\nInOrderTraversal : ";
    InOrderTraversal(root);

    cout<<"\nPreOrderTraversal : ";
    PreOrderTraversal(root);

    cout<<"\nPostOrderTraversal : ";
    PostOrderTraversal(root);

    cout<<"\nLevelOrderTraversal : ";
    LevelOrderTraversal(root);

    cout<<"\n\n";

    return 0;
}