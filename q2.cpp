//Write a c++ program to insert a new Node in any position in a singly Linked List
#include<iostream>
#include<string.h>
using namespace std;
class Node;
void displayList(Node *&);
void insertAtMiddle(int pos,Node *&head,Node *&tail,int data);
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
void insertAtMiddle(int pos,Node *&head,Node *&tail,int data)
{

    int len=findLength(head);
    cout<<"\n\nLength of the List is "<<len<<endl;
         if(pos==1)
         {
            insertAtHead(head,tail,data);
            return;
         }
         if(pos==len+1)
         {
            insertAtTail(head,tail,data);
            return;
         }

       Node *newNode=new Node(data);
       //Find prevNode and currNode;
       Node *prevNode=head;
       int i=1;
       while(i<pos-1)
       {
         cout<<"\nInserting at Middle--\n";
             prevNode=prevNode->next;
             i++;
       }
       cout<<prevNode->data<<endl;
       Node *currNode=prevNode->next;
       
       //Connect the next pointers 
       prevNode->next=newNode;
       newNode->next=currNode;
       cout<<"\nNode with data "<<newNode->data<<" has been inserted at "<<pos<<endl;
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
insertAtMiddle(4,head,tail,80);
displayList(head);
return 0;
}