//stacks with singly linked list
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
  int data;
  Node* next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

void pop(Node** head);
void push(Node** head , int x);
bool isEmpty(Node* head);
void printStack(Node* head);
int getSize(Node* head);

int main(void)
{ 

  cout<<"start entering commands\n";
  Node *head = NULL;
  

  while(true)
  {
    string s;
    cin>>s;

    if(s == "push")
    {
      int x;
      cin>>x;
      push(&head , x);
    }

    else if(s == "pop")
    {
        pop(&head);
    }

    else if(s == "isEmpty")
    {
        if(isEmpty(head))
          cout<<"YES , EMPTY\n";
        else
          cout<<"NOPE\n";
    }

    else if(s == "getSize")
    {
       cout<<getSize(head)<<"\n";
    }

    else if(s == "q")
      break;

    else if(s == "print")
     {
       printStack(head);
     }


  }

  return 0; 
}

void pop(Node** head)
{
  if(isEmpty(*head))
  {
    cout<<"EMPTY STACK...CAN'T POP\n";
    return;
  }

  *head = (*head)->next;
}

void push(Node** head , int x)
{
  Node* temp = new Node(x);
  if(*head == NULL)
  {
    *head = temp;
    return;
  }

  temp->next = *head;
  *head = temp;
  return;
}

bool isEmpty(Node* head)
{
  if(head == NULL) return true;

  return false;
}

void printStack(Node* head)
{
  if(head == NULL)
  {
    cout<<"EMPTY STACK\n";
    return;
  }

  Node* trav = head;
  while(trav)
  {
    cout<<trav->data<<" ";
    trav = trav->next;
  }

  cout<<"\n";
}

int getSize(Node* head)
{
  int len = 0;
  Node* trav = head;
  while(trav)
  {
    trav = trav->next;
    len++;
  }

  return len;
}