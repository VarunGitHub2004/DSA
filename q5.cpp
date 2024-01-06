//Write a program to insert a new Node at the middle of the doubly linked list
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
       //Connect the previous pointers
       newNode->prev=prevNode;
       currNode->prev=newNode;
       cout<<"\nNode with data "<<newNode->data<<" has been inserted at "<<pos<<endl;
}
int main()
{
Node *head=NULL;
Node *tail=NULL;
insertAtHead(head,tail,3);

insertAtHead(head,tail,2);

insertAtHead(head,tail,1);
//For checking that the prev pointer is connected to prevNode
// cout<<head->next->prev->data;

insertAtTail(head,tail,4);
insertAtTail(head,tail,5);

//For checking that the prev pointer is connected to prevNode
// cout<<head->next->prev->data;
// cout<<tail->prev->data;

insertAtTail(head,tail,6);

//For checking that the prev pointer is connected to prevNode

insertAtMiddle(7,head,tail,10);
cout<<head->next->next->prev->data<<endl;
displayList(head);
return 0;
}