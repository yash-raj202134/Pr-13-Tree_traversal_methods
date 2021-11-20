//  Level Order traversal of binary tree...
#include <iostream>
#include <stdlib.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

class Node *createNode(int data) //function to create a single node.. 
{
    Node *n;                         
    n = (Node *)malloc(sizeof(class Node)); 
    n->data = data;                        
    n->left = NULL;                        
    n->right = NULL;                       
    return n;
}

void preOrder(class Node* root)  //Pre Order traversal method..
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(class Node* root)  //postOrder traversal method..
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}
void inOrder(class Node* root)   //inOrder traversal method..
{
    if(root!=NULL)
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void print_currentlevel(Node *root, int level)   //function to print current level of node in iteration..
{
    if (root != NULL)
    {
        if (level == 1)
            cout << root->data << " ";

        else if (level > 1)
        {
            print_currentlevel(root->left, level - 1);
            print_currentlevel(root->right, level - 1);
        }
    }
}
int height(Node *node)  //function used to calculate height of the tree..
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
void levelOrder(class Node *root)   //Level order traversal method... 
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
        print_currentlevel(root, i);
}

void linkNode(Node *Root_node, Node *Left_node=NULL, Node *Right_node=NULL)  //function to link the nodes to make a tree..
{
    Root_node->left = Left_node;
    Root_node->right = Right_node;
}
int main(void)
{
    Node *p = createNode(7);  //Node creation..
    Node *p1 = createNode(5);
    Node *p2 = createNode(12);
    Node *p3 = createNode(17);
    Node *p4 = createNode(3);
    Node *p5 = createNode(2);
    Node *p6 = createNode(0);
    linkNode(p, p1, p2);  //node linking..
    linkNode(p1, p3, p4);
    linkNode(p2,p5);
    linkNode(p3,p6);
    cout<<"Preorder traversal   : ";  //preorder
    preOrder(p);
    cout<<"\nPostorder traversal  : ";  //postorder
    postOrder(p);
    cout<<"\nInorder traversal    : "; //inorder
    inOrder(p);
    cout<<"\nLevelorder traversal : ";  //levelorder
    levelOrder(p);

    return 0;
}