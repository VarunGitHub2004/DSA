//Write a program to perform all deletion operations of the doubly circular linked list
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
    do
    {
        cout<<temp->data<<"->";
         temp=temp->next;
    }
    while(temp!=head);

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
    tail->next=head;
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
 
    tail->next=head;
      
}

int findLength(Node *&head)
{
    int len=0;
       Node *temp=head;
       do
       {
        temp=temp->next;
        len++;
       }
       while(temp!=head);
cout<<"\n----------Length :-"<<len<<endl<<endl;
       return len;
}


void deleteNode(int pos,Node *&tail,Node *&head)
{ 
    int length=findLength(head);
   if(pos==1)
   {
     cout<<"Before deletion 🗑️\n\n";
    displayList(head);
    cout<<"Deleting head 🗑️\n\n";
      Node *temp=head;
      head=head->next;
      delete temp;
      tail->next=head;
      return;
   }
   if(pos==length)
   {
    cout<<"Before deletion  🗑️\n\n";
    displayList(head);
    cout<<"\n...Deleting last Node 🗑️\n";
    Node *temp=tail;
    tail=tail->prev;
    tail->next=head;
    delete temp;
    return;
   }
   //Find previous node and next node and current Node
   Node *prevNode=head;
   int i=0;
   while(i<pos-1)
   {
    prevNode=prevNode->next;
    i++;
   }
   Node *currNode=prevNode->next;
   cout<<"\nNode with data "<<currNode->data<<" has been deleted\n";
   Node *nextNode=prevNode->next->next;
   prevNode->next=nextNode;
   nextNode->prev=prevNode;
   delete currNode;
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
insertAtHead(head,tail,99);

deleteNode(3,tail,head);
cout<<"\nAfter deletion  🗑️\n\n";
displayList(head);

cout<<"Proof that it is a doubly circular linked list by showing the next and previous of tail\n";
cout<<"The next of tail : "<<tail->next->data<<endl;
cout<<"The prev of tail : "<<tail->prev->data<<endl;
return 0;
}