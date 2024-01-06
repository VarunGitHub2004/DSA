// Q8. Write a c++ program to convert singly linked list into circular linked list.
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
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
void display(Node *&head)
{
    cout<<"\nDisplaying the full linked list\n";
    Node *temp=head;
    do
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    while(temp!=head);

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
    tail=newNode;
    tail->next=head;
}

 int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    insertAtTail(head,tail,8);
    insertAtTail(head,tail,8);
    insertAtHead(head,tail,5);
    insertAtHead(head,tail,5);
    insertAtHead(head,tail,4);
    insertAtTail(head,tail,9);
    display(head);
    cout<<"\nProof that it is a circular linked list : \n";
    cout<<"tail->next->data : "<<tail->next->data<<endl;
    return 0;
}