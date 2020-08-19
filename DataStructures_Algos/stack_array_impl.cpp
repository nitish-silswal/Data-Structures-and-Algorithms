//rotating a circular linked list
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void pop(int* arr , int n , int* top);
void push(int* arr , int n , int x , int* top);
bool isEmpty(int*arr , int n , int top);
void printStack(int* arr , int n, int top);
int getSize(int top);

int main(void)
{ 

 cout<<"enter stack max_size\n";
  int n;
  cin>>n;

  int arr[n];
  int top = -1;

  while(true)
  {
    string s;
    cin>>s;

    if(s == "push")
    {
      int x;
      cin>>x;
      push(arr,n,x,&top);
    }

    else if(s == "pop")
    {
        pop(arr,n,&top);
    }

    else if(s == "isEmpty")
    {
        if(isEmpty(arr,n,top))
          cout<<"YES , EMPTY\n";
        else
          cout<<"NOPE\n";
    }

    else if(s == "getSize")
    {
        cout<<(top+1)<<"\n";
    }

    else if(s == "q")
      break;

    else if(s == "print")
     {
      printStack(arr,n,top);
     }


  }

  return 0; 
}

void pop(int* arr , int n , int* top)
{
  if(*top == -1){
    cout<<"EMPTY STACK\n";
    return;
  }

  (*top)--;
}

void push(int* arr , int n , int x , int* top)
{
  if(*top == n-1)
  {
    cout<<"FULL STACK\n";
    return;
  }

  (*top)++;
  arr[*top] = x;
}

bool isEmpty(int*arr , int n , int top)
{
  if(top == -1)
    return true;
  return false;
}

void printStack(int* arr , int n, int top)
{
  if(top == -1)
  {
    cout<<"EMPTY STACK\n";
    return ;
  }

  for(int i=top ; i>=0 ; i--)
    cout<<arr[i]<<" ";

  cout<<"\n";

}

int getSize(int top)
{
  return (top+1);
}