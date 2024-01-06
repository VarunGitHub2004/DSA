//Write a c++ program to create a singly linked list of n nodes and display it in reverse order
#include<iostream>
#include<string.h>
using namespace std;
class Node;
void displayList(Node *&);
class Node{
public:
int data;
Node*next;
Node()
{
    data=0;
    next=NULL;
}
Node(int data)
{
    this->data=data;
    next=NULL;
}
};

Node* reverseList(Node *&head)
{

    cout<<"Displaying Reversed Linked List---\n";
    Node *prevNode=NULL;
    Node *currNode=head;
    Node *frwdNode;

    while(currNode!=NULL)
    {
        frwdNode=currNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=frwdNode;
    }
    return prevNode;
}

void displayReverseList(Node *&head)
{
    Node *prev=reverseList(head);
    displayList(prev);
}
void insertAtTail(Node *&head,Node *&tail,int data)
{
    if(head==NULL)
    {
        Node *newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
       Node *newNode=new Node(data);
       tail->next=newNode;
       tail=newNode;
}
void insertAtHead(Node *&head,Node *&tail,int data)
{
    if(head==NULL)
    {
        Node *newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
       Node *newNode=new Node(data);
       newNode->next=head;
       head=newNode;
}

void displayList(Node *&head)
{
    cout<<"\nDisplaying Linked List--------------\n";
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
         temp=temp->next;
    }
    cout<<endl;
}

int main()
{
Node *head=NULL;
Node *tail=NULL;
insertAtTail(head,tail,20);
insertAtHead(head,tail,1);
insertAtHead(head,tail,30);
insertAtTail(head,tail,80);
insertAtHead(head,tail,4);
insertAtHead(head,tail,90);
displayList(head);
displayReverseList(head);
return 0;
}