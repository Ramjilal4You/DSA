//Program for mirror tree

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/* A binary tree node has data, pointer to left child and a pointer to right child */
struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(vector<int>& ip) {
    // Corner Case
    if (ip.size() == 0 || ip[0] == 0) return NULL;

    // Create the root of the tree
    Node *root = new Node(ip[0]);

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        int currVal = ip[i];

        // If the left child is not null
        //if (currVal != 0) {

            // Create the left child for the current node
            currNode->left = new Node(currVal);

            // Push it to the queue
            queue.push(currNode->left);
        //}

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        //if (currVal != 0) {

            // Create the right child for the current node
            currNode->right = new Node(currVal);

            // Push it to the queue
            queue.push(currNode->right);
        //}
        i++;
    }

    return root;
}

/* Helper function to test mirror(). Given a binary tree, 
   print out its data elements in increasing sorted order.*/
void levelOrder(struct Node *root) {
    if (root == NULL) return;

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    //traverse for all nodes
    while (!queue.empty()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value
        cout<<currNode->data<<" ";

        // If the left child is not null
        if (currNode->left != nullptr)
            queue.push(currNode->left); // Push it to the queue

        // If the right child is not null
        if (currNode->right != nullptr)
            queue.push(currNode->right); // Push it to the queue
    }
}

/* A binary tree node has data, pointer to left child and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


void mirrorUsingPreOrderTraversal(Node* node) {
    if(node==nullptr)
        return;
        
    swap(node->left, node->right);

    mirrorUsingPreOrderTraversal(node->left);
    mirrorUsingPreOrderTraversal(node->right);
}

/* Helper function to test mirror().*/
void mirrorUsingPostOrderTraversal(struct Node *node) {
    if (node == NULL) return;

    mirrorUsingPostOrderTraversal(node->left);
    mirrorUsingPostOrderTraversal(node->right);

    swap(node->left, node->right);
}

/* Helper function to test mirror().*/
void mirrorUsingInOrderTraversal(struct Node *node) {
    if (node == NULL) return;

    mirrorUsingInOrderTraversal(node->left);
    swap(node->left, node->right);
    mirrorUsingInOrderTraversal(node->left);
}

// Function to convert a binary tree into its mirror tree.
void mirror(Node* node) {
    int op;
    while(1){
        cout<<"Please Enter option (1-3) : ";
        cin>>op;
        switch (op)
        {
        case 1:
            cout<<"\nMirror Using PreOrder Traversal\n";
            mirrorUsingPreOrderTraversal(node);
            break;
        case 2:
            cout<<"\nMirror Using PostOrder Traversal\n";
            mirrorUsingPostOrderTraversal(node);
            break;
        case 3:
            cout<<"\nMirror Using InOrder Traversal\n";
            mirrorUsingInOrderTraversal(node);
            break;
        default:
            return;
        }
        cout<<"After Mirror of tree : ";
        levelOrder(node);
        cout << "\n";
    }
}


//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int nc; //node count
    cout<<"Please Enter the tree node Count : ";
    cin>>nc;
    cout<<"Please Enter the Tree node values : ";
    vector<int> arr(nc, 0);
    for (int i = 0; i < nc; i++) // input the array
    {
        cin >> arr[i];
    }
    Node *root = buildTree(arr);

    cout<<"Before Mirror of tree : ";
    levelOrder(root);
    cout<<endl;

    mirror(root);

    
    

    return 0;
}
// } Driver Code Ends