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
    static Node *odd_evenLL1(Node *head)
    {
        vector<int> vec;
        Node *temp1 = head;
        Node *temp2 = head->next;
        Node *temp3 = head;
        while (temp1 != nullptr && temp1->next != nullptr)
        {
            vec.push_back(temp1->data);
            temp1 = temp1->next->next;
        }
        if (temp1)
        {
            vec.push_back(temp1->data);
        }

        while (temp2 != nullptr && temp2->next != nullptr)
        {
            vec.push_back(temp2->data);
            temp2 = temp2->next->next;
        }

        if (temp2)
        {
            vec.push_back(temp2->data);
        }

        int i = 0;
        while (temp3 != nullptr)
        {
            temp3->data = vec[i];
            temp3 = temp3->next;
            i++;
        }

        return head;
    }
    static Node *odd_evenLL2(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        Node *odd = head;
        Node *even = head->next;
        Node *evenHead = head->next;

        while (even != nullptr && even->next != nullptr)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;

        return head;
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

    Node *res1 = Node::odd_evenLL1(head);
    Node::traverse(res1);
    Node *res2 = Node::odd_evenLL2(head);
    Node::traverse(res2);

    /*****************************************************************************************/
    // Clean up memory
    //  delete[] head;

    return 0;
}