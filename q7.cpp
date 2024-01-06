// Write a program to delete duplicated node from the doubly linked list
#include <iostream>
#include <string.h>
using namespace std;
class Node;
void displayList(Node *&);
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};


// void removeDuplicateElements(Node *&head)
// {
//     Node *ptr1,*ptr2,*dup;
//     ptr1=head;
//     while(ptr1!=NULL && ptr1->next!=NULL)
//     {
//         ptr2=ptr1;
//         while(ptr2->next!=NULL)
//     {
//         if(ptr1->data==ptr2->next->data)
//         {
//               dup=ptr2->next;
//             ptr2->next=ptr2->next->next;
//             delete dup;
//         }
//         else
        
//             ptr2=ptr2->next;
    
//     }
// ptr1=ptr1->next;
//     }
// }


void removeDuplicateElements(Node *&head)
{
    Node *ptr1,*ptr2,*dup;
    ptr1=head;
    while(ptr1!=NULL && ptr1->next!=NULL)
    {
         ptr2=ptr1;
         while(ptr2->next!=NULL)
         {
             if(ptr1->data==ptr2->next->data)
             {
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                delete dup;
             }
             else
             {
               ptr2=ptr2->next;

             }
             
         }
         ptr1=ptr1->next;
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void displayList(Node *&head)
{
    cout << "\nDisplaying Linked List--------------\n";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(head, tail, 20);
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 20);
    insertAtTail(head, tail, 80);
    insertAtHead(head, tail, 4);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 80);
    insertAtHead(head, tail, 80);
    removeDuplicateElements(head);
    displayList(head);
    return 0;
}