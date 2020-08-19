//queue using linked list
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next ;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void enqueue(Node** head , Node** tail , int x);
void dequeue(Node** head , Node** tail );
bool isEmpty(Node* head);
int getSize(Node* head);
void print(Node* head);


int main(void)
{
    Node *head = NULL , *tail = NULL;

    while(true)
    {
        string s;
        cin>>s;

        if(s == "enq")
        {
            int x;
            cin>>x;
            enqueue(&head , &tail , x);
        }

        else if(s == "deq")
        {
            dequeue(&head , &tail);
        }

        else if(s == "isEmpty")
        {
            if(isEmpty(head))
                cout<<"EMPTY STACK\n";

            else
                cout<<"NO\n";
        }

        else if(s == "getSize")
        {
            cout<<getSize(head)<<"\n";
        }

        else if(s == "print")
        {
            print(head);
        }

        else if(s == "q")
            break;
    }




    return 0;
}

void enqueue(Node** head , Node** tail , int x)
{   
    Node* temp = new Node(x);
    if(*head == NULL)
    {
        *head = temp;
        *tail = temp;
        return;
    }

    (*tail)->next = temp;
    *tail = temp;
    return;
}


void dequeue(Node** head , Node** tail)
{
    if(isEmpty(*head))
    {
        cout<<"EMPTY STACK\n";
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    delete(temp);
    return;
}


bool isEmpty(Node* head)
{
    if(head == NULL) return true;

    else
        return false;
}



int getSize(Node* head)
{
    if(head == NULL) return 0;

    Node* curr = head;
    int len = 0;
    while(curr)
    {
        curr = curr->next;
        len++;
    } 

    return len;
}


void print(Node* head)
{
    if(head == NULL)
    {
        cout<<"EMPTY STACK\n";
        return ;
    }

    Node* curr = head;
    while(curr)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }

    cout<<'\n';
}
