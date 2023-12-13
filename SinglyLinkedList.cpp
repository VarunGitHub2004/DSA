// Write code for singly linked list
#include <iostream>
#include <string.h>
using namespace std;
class Node;
void insertAtHead(Node *&head);
void insertAtPosition(int, Node *&, Node *&, int);
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

int findLength(Node *&head)
{
    int i = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
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


    // step1
    Node *newNode = new Node(data);
    // step2 Connect to head
    newNode->next = head;
    // step3 Update the head node
    head = newNode;
    cout<<"\nHead inserted with data  "<<head->data<<endl;
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

    // step1 create a new Node
    Node *newNode = new Node(data);
    // step2 connect to tail
    tail->next = newNode;
    // step3 update tail
    tail = newNode;

    cout<<"\nTail inserted with data "<<tail->data<<endl;
}
void displayList(Node *&head, Node *&tail)
{
    cout << endl;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}


void insertAtPosition(int pos, Node *&head, Node *&tail, int data)
{
    int len = findLength(head);
    // cout << len;
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    if(pos==len)
    {
        insertAtTail(head,tail,data);
        return;
    }
    if(pos>len || pos<1)
    {
        cout<<"Invalid position";
        return;
    }
    cout << endl;
    // step1 Find prev and curr
    Node *prevNode = head;
    int i = 1;
    while (i < pos - 1)
    {
        prevNode = prevNode->next;
        i++;
    }
    Node *currNode = prevNode->next;
    // Step2 Create a new Node
    Node *newNode = new Node(data);
    // Step3 Connect to prev Node
    prevNode->next = newNode;
    // Step4 Connect to curr Node
    newNode->next = currNode;
     
  
    cout <<"\nNode with data "<<newNode->data<<" has been inserted at postion "<<pos<< endl;
}

void deleteNode(int pos,Node *&head,Node *&tail)
{
     int len = findLength(head);
    // cout << len;

    if(pos==1)
     {
        cout<<"\nDeleting Head...\n";
        // step1
        Node *temp=head;
        // step2
        head=head->next;
        // step3
        delete temp;
        return;
     }

     if(pos==len)
     {
        cout<<"\nDeleting Tail...\n";
        //step1 Create a temp
        Node *temp=tail;
        //step2 find prev
        Node *prevNode=head;
        int i=1;
        while(i<pos-1){
            prevNode=prevNode->next;
            i++;
        }
        //step3 update tail Node;
        tail=prevNode;
        //step4 delete temp
        delete temp;
        return;
     }
    //Step1 Find prevNode,currNode,nextNode
    Node *prevNode=head;
    int i=1;
    while(i<pos-1)
    {
        prevNode=prevNode->next;
        i++;
    }
    Node *currNode=prevNode->next;
    int currData=currNode->data;
    Node *nextNode=currNode->next;
    //Step2 Connect prevNode to nextNode
    prevNode->next=nextNode;
    //Step3 //delete currNode
    delete currNode;

    cout<<"\nNode with data "<<currData<<" has been deleted from position "<<pos<<endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 29);
    displayList(head, tail);

    insertAtHead(head, tail, 28);
    displayList(head, tail);

    insertAtHead(head, tail, 27);
    displayList(head, tail);

    insertAtTail(head, tail, 91);
    displayList(head, tail);

    insertAtTail(head, tail, 90);
    displayList(head, tail);

    insertAtPosition(4, head, tail, 89);
    displayList(head, tail);

    cout<<"\nBefore Deletion\n";
    displayList(head, tail);

    deleteNode(6,head,tail);
    cout<<"\nAfter Deletion\n";
    
    displayList(head, tail);

    return 0;
}