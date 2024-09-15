// develop binary tree from double linked list

#include<iostream>
using namespace std;

class Node
{
    int data;
    Node* left;
    Node* right;
    public:
    Node(){}
    Node(int val):data(val),left(nullptr),right(nullptr){} 
    friend class BTDLL;
};
class BTDLL
{
    Node * root;

    void insertNode(Node*& node, int value) {
        if(node==nullptr)
        {
            node = new Node(value);
            return;
        }
        if(value<node->data)
        {
            if(node->left==nullptr)
            {
                node->left = new Node(value);
                node->left->right = node;
            }
            
            else
            {
                insertNode(node->left,value);
            }
        }
        else
        {
            if(node->right==nullptr)
            {
                node->right = new Node(value);
                node->right->left = node;
            }
            else
            {
                insertNode(node->right,value);
            }
        }
    }
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;

        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }
    void deleteTree(Node* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    public:
    BTDLL(): root(nullptr){}
    ~BTDLL()
    {
        deleteTree(root);
    }
    void insert(int val)
    {
        insertNode(root, val);
    }
    void display()
    {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};
int main()
{
   BTDLL obj1;
   obj1.insert(11);
   obj1.insert(22);
   obj1.insert(33);
   obj1.insert(44);
   obj1.insert(55);
   obj1.insert(66);
   obj1.display();
    return 0;
}