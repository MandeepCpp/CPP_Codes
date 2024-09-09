#include <iostream>
#include <vector>
#include <map>
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
    /*****************************************************************************************/
    static Node *reverseLinkedList(Node *head)
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    static Node *reverseLinkedListRecursion(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        Node *newHead = reverseLinkedListRecursion(head->next);
        Node *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
    static Node *reverseKLinkedList(Node *head, int k)
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        int count = 0;

        while (current != nullptr && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        if (next != nullptr)
        {
            head->next = reverseKLinkedList(next, k);
        }

        return prev;
    }
    /*********************************************************************************************/
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

    Node *res1 = Node::reverseLinkedList(head);
    Node::traverse(res1);

    Node *res2 = Node::reverseKLinkedList(head,3);
    Node::traverse(res2);
    /*****************************************************************************************/
    // Clean up memory
    //  delete[] head;

    return 0;
}