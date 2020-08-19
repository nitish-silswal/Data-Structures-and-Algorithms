// ====================  _/\_ NITISH SILSWAL  _/\_ =====================
// Segment tree without recursion

#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define pb                  push_back
#define mp                  make_pair
#define foritr(x)           for(auto it = x.begin() ; it!= x.end() ;  it++)
#define fo(i , n)           for(int i=0 ; i <n ; i++)
#define foo(i,k,n)          for(int i=k ; i<n ; i++)
#define sortt(x)            sort(x.begin() , x.end())
#define fs                  first
#define sec                 second
#define MOD                 998244353
#define MAX                 1e9
#define MIN                 -1e9
#define fastio()            ios_base::sync_with_stdio(0);cin.tie();cout.tie(0);
#define pii                 pair<int,int>
#define tests()             int testcases;cin>>testcases;while(testcases--)
#define vi                  vector<int>
#define vll                 vector<ll>
#define vvi                 vector<vi>
#define pll                 pair<ll,ll>
#define pii                 pair<int,int>
#define all(p)              p.begin(),p.end()
#define deb(x)              cout<<#x<<" "<<x<<"\n";  
#define setP(num , x)       cout<<fixed<<setprecision(x)<<num<<"\n"
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

void buildTree(int* Tree , int *arr , int n)
{
    for(int i=n ; i<(n << 1) ; i++)
        Tree[i] =arr[i-n];
    
    for(int i=n-1 ; i>=1 ; i--)
        Tree[i] = Tree[i << 1] + Tree[(i << 1) + 1];
    
    Tree[0] = -1;
   
}

void update(int* arr , int* Tree, int n , int index , int val)
{
    arr[index] = val;
    int startNode = index + n;
    Tree[startNode] = val;
    startNode >>= 1;

    while(startNode >= 1)
    {   
        Tree[startNode]  = Tree[startNode << 1] + Tree[(startNode << 1)+ 1];
        startNode >>= 1;
    }

}

int Query(int* arr, int* Tree , int n , int l , int r) // range is [l , r] -> both inclusive
{
    l += n;
    r += n;
    int res = 0;
    while (l <= r)
    {
        if(l & 1) // if l is odd -> it is a right child -> add to res and move to the parent node of (l+1), i.e right cousin's parent , hence l++
        {
            res += Tree[l];
            l++;
        }
        
        if(!(r & 1)) // r is even -> left child -> add to res and move to the parent node of the (r-1), i.e left cousin's parent , hence r--;
        {
            res += Tree[r];
            r--;
        }

        l >>= 1;
        r >>= 1;
    }

    return res;

}

int main(void)
{   
    fastio()
    // freopen("/home/nitish/Desktop/inp.txt" , "r" , stdin);
    // freopen("/home/nitish/Desktop/out.txt" , "w" , stdout);
   int arr[] = {1,2,3,4 , 5 };
   int n = sizeof(arr) / sizeof(arr[0]);

   // ===================== SIZE of tree = 2*N and the Tree is 1 indexed=================
   int Tree[2*n];
   buildTree(Tree , arr, n);

   for(int i=0 ; i<2*n ; i++)
    cout << Tree[i] << "  ";
  
  update(arr, Tree , n , 0 , 10);

    for(int i=0  ; i < 2*n ; i++)
        cout << Tree[i] << "  ";
    
    cout << "\n";

   cout << Query(arr,Tree , n  , 1 , n-2) <<"\n";


    return 0;
}
