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
    static int length(Node *head)
    {
        Node *ptr = head;
        int count = 0;
        while (ptr != nullptr)
        {
            ptr = ptr->next;
            count++;
        }
        return count;
    }

    static int IsIntersection(Node *&head1, Node *&head2)
    {
        int len1 = length(head1);
        int len2 = length(head2);
        Node *ptr1 = nullptr;
        Node *ptr2 = nullptr;
        int k = 0;

        if (len1 >= len2)
        {
            ptr1 = head1;
            ptr2 = head2;
            k = len1 - len2;
        }
        else
        {
            ptr1 = head2;
            ptr2 = head1;
            k = len2 - len1;
        }
        while (k)
        {
            ptr1 = ptr1->next;
            k--;
        }
        while (ptr1->next != nullptr && ptr2->next != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (ptr1 == ptr2)
            {
                return ptr1->data;
            }
        }
        return -1;
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

    Node *head1 = new Node(20);
    head1 = Node::insertAtFirst(head1, 15);      // Update head to new node after insertion
    head1 = Node::insertAtFirst(head1, 7);       // Update head to new node after insertion
    head1 = Node::insertAtFirst(head1, 3);       // Update head to new node after insertion
    head1 = Node::insertAtFirst(head, 2);       // Update head to new node after insertion
    head1 = Node::insertAtFirst(head1, 1);       // Update head to new node after insertion
    head1 = Node::insertInBetween(head1, 10, 4); // Update head to new node after insertion
    head1 = Node::insertAtLast(head1, 25);       // Update head to new node after insertion
    Node::traverse(head1);

    /*****************************************************************************************/

    cout<<Node::IsIntersection(head, head1)<<endl;
    /*****************************************************************************************/
    // Clean up memory
    //  delete[] head;

    return 0;
}