//Write a c++ program to delete  the last Node of any singly Linked List
#include<iostream>
#include<string.h>
using namespace std;
class Node;
void displayList(Node *&);
void deleteLastNode(Node *& ,Node *&);
void insertAtHead(Node *&head,Node *&tail,int data);
void insertAtTail(Node *&head,Node *&tail,int data);
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

void insertAtTail(Node *&head,Node *&tail,int data)
{
    cout<<"\nInserting Tail-----\n";

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
    cout<<"\nInserting head-----\n";
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

int findLength(Node *&head)
{
    int len=0;
       Node *temp=head;
       while(temp!=NULL)
       {
        temp=temp->next;
        len++;
       }
       return len;
}

void deleteLastNode(Node *&tail,Node *&head)
{
    int length=findLength(head);
    cout<<"\n...Deleting last Node\n";
    Node *temp=tail;
    int i=1;
    Node *lastSecondNode=head;
    while(i<length-1)
    {
        lastSecondNode=lastSecondNode->next;
        i++;
    }
    tail=lastSecondNode;
    tail->next=NULL;
     delete temp;
}
int main()
{
Node *head=NULL;
Node *tail=NULL;
insertAtTail(head,tail,20);
displayList(head);

insertAtHead(head,tail,1);
displayList(head);

insertAtHead(head,tail,30);
displayList(head);

insertAtTail(head,tail,80);
displayList(head);

insertAtHead(head,tail,4);
displayList(head);

insertAtHead(head,tail,90);
displayList(head);

deleteLastNode(tail,head);
displayList(head);
return 0;
}