#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;

	Node(int x)
	{
		data = x;
		next = NULL;
		prev = NULL;
	}
};


bool isPrime(int n)
{
	if(n == 1) return true;

	if(n == 2 || n == 3 || n == 5) return true;

	for(int i=2 ; i*i<=n ; i++)
	{
		if(n % i == 0)
			return false;
	}

	return true;
}

void deleteNode(Node** head , Node** temp)
{
   if(*head == NULL || *temp == NULL) return;

   if((*head) == *temp)
   {
   	 *head = (*temp)->next;
   	 return;   	 
   }

   if((*temp)->next)
   	(*temp)->next->prev = (*temp)->prev;

   if((*temp)->prev)
   	(*temp)->prev->next = (*temp)->next;

   free(*temp);


}

void deleteNodesSmallerThan(Node** head , int x)
{
	if(*head == NULL)return;

	if((*head)->next == NULL) // single element
	{
		if((*head)->data < x)
			*head = NULL;

		return;
	}

	Node* curr = *head;
	while(curr)
	{
		Node* temp = curr->next;

		if(curr->data < x)
			deleteNode(head , &curr);

		curr = temp;
	}
}


void deleteEvenNodes(Node** head)
{
	if(*head == NULL) return;

	Node* curr = *head;
	while(curr)
	{	
		Node* temp = curr->next;
		if(curr->data % 2 == 0)
			deleteNode(head , &curr);

		curr = temp;
	}
}

void deleteOddNodes(Node** head)
{
	if(*head == NULL) return ;

	Node* curr = *head;
	while(curr)
	{
		Node* temp = curr->next;

		if(curr->data % 2 == 1)
			deleteNode(head , &curr);

		curr = temp;
	}

}

void deletePrimeNodes(Node** head)
{
	if(*head == NULL)return;

	Node *curr = *head;
	while(curr)
	{	
		Node* temp = curr->next;
		if(isPrime(curr->data))
			deleteNode(head , &curr);

		curr = temp;
	}
}


void printDoublyListForward(Node* head)
{
	if(head == NULL)
	{
		cout<<"empty list\n";
		return;
	}

	Node* curr = head;
	while(curr)
	{
		cout<<curr->data<<" ";
		curr = curr->next; 
	}

	cout<<"\n";
}

void printDoublyListBackward(Node* tail)
{
   if(tail == NULL)
   {
   	cout<<"empty list\n";
   	return;
   }

   Node* curr = tail;
   while(curr)
   {
   	cout<<curr->data<<" ";
   	curr = curr->prev;
   }

   cout<<"\n";
}



void insertEmpty(Node** head , Node** tail , int x)
{
	if(*head != NULL)return;

	Node* temp = new Node(x);
	*head = temp;
	*tail = temp;
	temp->prev = NULL;
	temp->next = NULL;
}


void insertFront(Node** head , Node** tail , int x)
{ 
	if(*head  == NULL)
	{
		insertEmpty(head ,tail ,x);
		return;
		
	}

	Node* temp = new Node(x);
	(*head)->prev = temp;
	temp->next = *head;
	*head  =temp;

}

void insertEnd(Node** head , Node** tail , int x)
{
	if(*tail == NULL)
	{
		insertEmpty(head,tail,x);
		return;
	}

	Node* temp = new Node(x);
	(*tail)->next = temp;
	temp->prev = (*tail);
	*tail = temp;

}


int main(void)
{
	
	Node *head = NULL , *curr = NULL , *tail = NULL;
	int n,x;
	cin>>n;
	for(int i=0 ; i<n  ;i++)
	{
		cin>>x;
		Node* temp = new Node(x);

		if(i == 0)
		{
			head = temp;
			curr = temp;
		}

		else
		{
			curr->next = temp;
			temp->prev = curr;
			curr = curr->next;
		}
	}

	tail = curr;
	curr->next = NULL;
	tail->next = NULL;

	
	deleteNodesSmallerThan(&head , 10);
	printDoublyListForward(head);

}


