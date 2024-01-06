//Write a program to delete last node of the doubly linked list
#include<iostream>
#include<string.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        data=0;
        next=NULL;
        prev=NULL;
    }
    Node(int data)
    {
       this->data=data;
       next=NULL;
       prev=NULL;
    }
};

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
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
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
    newNode->prev=tail;
    tail=newNode;
}



void deleteLastNode(Node *&tail,Node *&head)
{
    cout<<"Before deletion\n\n";
displayList(head);
    cout<<"\n...Deleting last Node\n";
    Node *temp=tail;
    Node *lastSecondNode=tail->prev;
    tail=lastSecondNode;
    tail->next=NULL;
    delete temp;
}



int main()
{
Node *head=NULL;
Node *tail=NULL;
insertAtHead(head,tail,3);
insertAtHead(head,tail,2);
insertAtHead(head,tail,1);
insertAtTail(head,tail,4);
insertAtTail(head,tail,5);
insertAtTail(head,tail,6);

deleteLastNode(tail,head);
cout<<"\nAfter deletion\n\n";
displayList(head);
return 0;
}