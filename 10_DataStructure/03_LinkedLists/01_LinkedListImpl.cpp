#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
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

    // Destructor to release allocated memory
    ~Node()
    {
        delete next; // This will recursively delete all following nodes
    }
};
int main()
{
    Node *head = new Node(20);
    Node::traverse(head);

    head = Node::insertAtFirst(head, 15); // Update head to new node after insertion
    Node::traverse(head);

    head = Node::insertAtFirst(head, 7); // Update head to new node after insertion
    head = Node::insertAtFirst(head, 3); // Update head to new node after insertion
    head = Node::insertAtFirst(head, 2); // Update head to new node after insertion
    head = Node::insertAtFirst(head, 1); // Update head to new node after insertion
    Node::traverse(head);

    head = Node::insertInBetween(head, 10, 4); // Update head to new node after insertion
    Node::traverse(head);

    head = Node::insertAtLast(head, 25); // Update head to new node after insertion
    Node::traverse(head);

    // Clean up memory
    delete head;

    return 0;
}