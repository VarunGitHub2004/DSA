// Q9. Write a c++ program to merge a linked list into another linked list.
#include <iostream>
#include <string.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
    static int count;

public:
    Node *head;
    LinkedList()
    {
        head = NULL;
        count++;
    }
    void insertNode(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL || data < head->data)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *prevNode = head;
            while (data > prevNode->data && prevNode->next != NULL)
            {
                prevNode = prevNode->next;
            }
            Node *currNode = prevNode->next;
            prevNode->next = newNode;
            newNode->next = currNode;
        }
    }

    void display()
    {
        cout << endl;
        cout << "\nDisplaying Linked List no " << count << "...\n";
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

LinkedList mergeSortLinkedList(LinkedList L1,LinkedList L2)
{
  Node *curr1=L1.head;
  Node *curr2=L2.head;
  
  //Finding tail of List 1
  while(curr1->next!=NULL)
  {
    curr1=curr1->next;
  }
  Node *tail=curr1;
  tail->next=curr2;
return L1;
}

int LinkedList::count;

int main()
{
    LinkedList L1;
    L1.insertNode(11);
    L1.insertNode(12);
    L1.insertNode(40);
    L1.insertNode(10);
    L1.display();

    LinkedList L2;
    L2.insertNode(1);
    L2.insertNode(2);
    L2.insertNode(3);
    L2.insertNode(8);
    L2.display();
   
   LinkedList L3=mergeSortLinkedList(L1,L2);
   L3.display();
    
    return 0;
}