//Create a doubly linked list of n nodes count the number of nodes
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


int main()
{
Node *head=NULL;
Node *tail=NULL;
insertAtHead(head,tail,3);

insertAtHead(head,tail,2);

insertAtHead(head,tail,1);
//For checking that the prev pointer is connected to prevNode
    cout<<head->next->prev->data;

insertAtTail(head,tail,4);
insertAtTail(head,tail,5);
insertAtTail(head,tail,6);
displayList(head);

int len=findLength(head);
cout<<"The no of nodes in this list:-"<<len<<endl;

return 0;
}