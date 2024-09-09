#include <iostream>
#include<vector>
using namespace std;

class Node
{
    

public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
    Node(int val, Node *addr) : data(val), next(addr) {}

    // Static function for traversal to avoid requiring an instance
    static void traverse(Node *head)
    {
        while (head != nullptr)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    // Function to insert a node at the beginning
    static Node *insertAtFirst(Node *head, int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            newNode->next = nullptr;
            return newNode;
        }
        newNode->next = head;
        return newNode;
    }

    // Function to insert a node in between
    static Node *insertInBetween(Node *head, int val, int index)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            newNode->next = nullptr;
            return newNode;
        }
        Node *p = head;
        int i = 0;
        while (i != index - 1)
        {
            p = p->next;
            i++;
        }
        newNode->next = p->next;
        p->next = newNode;
        return head;
    }

    // Function to insert a node at last
    static Node *insertAtLast(Node *head, int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            newNode->next = nullptr;
            return newNode;
        }

        Node *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        newNode->next = nullptr;
        p->next = newNode;
        return head;
    }

    static void printMiddleElement(Node *head)
    {
        Node *fastptr = head;
        Node *slowptr = head;

        while (fastptr != nullptr && fastptr->next != nullptr)
        {
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
        }

        cout << "Middle eleemnt : " << slowptr->data << endl;
    }

    // Destructor to release allocated memory
    ~Node()
    {
        delete next; // This will recursively delete all following nodes
    }
};
int main()
{
    Node *head = new Node(20);
    head = Node::insertAtFirst(head, 15);      // Update head to new node after insertion
    head = Node::insertAtFirst(head, 7);       // Update head to new node after insertion
    head = Node::insertAtFirst(head, 3);       // Update head to new node after insertion
    head = Node::insertAtFirst(head, 2);       // Update head to new node after insertion
    head = Node::insertAtFirst(head, 1);       // Update head to new node after insertion
    head = Node::insertInBetween(head, 10, 4); // Update head to new node after insertion
    head = Node::insertAtLast(head, 25);       // Update head to new node after insertion
    Node::traverse(head);


    /*****************************************************************************************/


    Node::printMiddleElement(head);

    
    vector<int> v;
    while (head != NULL)
    {
        v.push_back(head->data);
        head = head->next;
    }
    cout << "Middle Value Of Linked List is :";
    cout << v[v.size() / 2] << endl;



    /*****************************************************************************************/
    // Clean up memory
    delete head;

    return 0;
}