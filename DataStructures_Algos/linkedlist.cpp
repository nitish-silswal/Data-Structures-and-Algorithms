#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node* next;

public:
 Node(int x);
 Node();

};

Node::Node(int x)
{
  this->data = x;
  this->next = NULL;
}

Node::Node()
{
  this->data = 0;
  this->next = NULL;
}


class MyLinkedList
{
public:
  Node* head;

public:
  MyLinkedList();
  void printList();
  int getSize();
  void append(int x);
  void addFirst(int x);
  void deleteList();
  void reverseList();

};

MyLinkedList :: MyLinkedList()
{
  this->head = NULL;
}

int MyLinkedList :: getSize()
{
  if(head == NULL)
    return 0;

  else
  {
    int len = 0;
    Node* temp = head;

    while(temp != NULL)
    {
      temp = temp->next;
      len++;
    }

    return len;
  }

}

void MyLinkedList :: printList()
{
  if(head == NULL)
  { cout<<"EMPTY LIST\n";
    return ;
  }

  Node* temp = head;

  while(temp != NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }

  cout<<"\n";
}

void MyLinkedList :: append(int x)
{
  Node* attach = new Node();
  attach->data = x;
  attach->next = NULL;

  if(head == NULL)
  {
    head = attach;
    return;
  }

  Node* temp = head;

  while(temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = attach;

}

void MyLinkedList :: addFirst(int x)
{
  if(head == NULL)
  {
     head = new Node(x);
     return ;
  }

  Node* front = new Node(x);
  front->next = head;
  head = front;


}

void MyLinkedList :: deleteList()
{
  Node* temp = head;
  Node* curr = temp;
  if(head == NULL) return;

  while(temp != NULL)
  {
    curr = temp;
    delete(curr);
    temp = temp->next;
  }

  head = NULL;
}


void MyLinkedList:: reverseList()
{
  if(head == NULL)
  {
    cout<<"empty list\n";
    return;
  }

  Node* temp = NULL;
  Node* curr = head;
  Node* prev = NULL;

  while(curr != NULL)
  {
    temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  Node* newHead = prev;
  temp = newHead;

  while(temp != NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }

  cout<<"\n";

}

int main(void)
{
  MyLinkedList* ll = new MyLinkedList();
 
 for(int i=0 ; i<10 ; i++)
  ll->append(i+1);

  ll->printList();
  ll->reverseList();
 

  return 0;
}

// void swapHeadTail(Node** head)
// {
//   if(*head == NULL || (*head)->next == NULL)
//     return;

//   Node* curr = *head;
//   while(curr->next->next)
//     curr = curr->next;

//   Node* last = curr->next;
//   curr->next = NULL;

//   Node* first = *head;

//   *head = (*head)->next;

//   curr->next = first;
//   curr->next->next = NULL;

//   last->next = *head;
//   *head = last;

// }
