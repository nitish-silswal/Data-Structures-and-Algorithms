// SUM OF ALL NUMBERS IN A GIVEN RANGE -> SQRT DECOMPOSITION METHOD

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


void preprocess(int* arr , int* blocks , int n) // O(N) -> one time
{
    int blk_Size = sqrt(n);
    
    for(int i=0 ; i<blk_Size ; i++)
    {
        int start = blk_Size*i;
        int end = start + blk_Size;
        int sum = 0;
        for(int j=start ; j<end ; j++)
            sum += arr[j];
        
        blocks[i] = sum;
            
    }

}

void update(int* arr , int *blocks , int  n ,int index , int val ) // O(1) ->very fast updates :)
{
    int blk_Size = sqrt(n);
    int prev_val = arr[index];
    arr[index] = val;

    int modifiedBlock = index/blk_Size;
    blocks[modifiedBlock] += (arr[index] - prev_val);
    
}

int Query(int *arr , int* blocks ,int l , int r , int n ) // O(sqrt(n))
{   
    if(l == r){
        return arr[l];
    }

    int blk_Size = sqrt(n) , res = 0 , startBlock = l/blk_Size , endBlock = r/blk_Size;

    if(startBlock == endBlock)
    {
        for(int i=l ; i<=r; i++)
            res += arr[i];
        
        return res;
    }

    for(int i=l ; i < (startBlock+1)*blk_Size ;  i++)
        res += arr[i];

    for(int i= endBlock*blk_Size ; i<=r ; i++)
        res += arr[i];

    for(int i=startBlock+1 ; i<endBlock ; i++)
        res += blocks[i];
    
    return res;

}


int main(void)
{   
    fastio()
    // freopen("/home/nitish/Desktop/inp.txt" , "r" , stdin);
    // freopen("/home/nitish/Desktop/out.txt" , "w" , stdout);
    
    int arr[] = {1,5,2,4,6, 1,3,5,7};
    int n = sizeof(arr)/sizeof(arr[0]); // n = 9
    int size = sqrt(n);
    int blocks[size];

    preprocess(arr , blocks , n);

    cout << Query(arr , blocks, 0, n-1, n) << "\n"; // sum of all numbers in
    update(arr ,blocks , n , 0 , 11);   
    cout << Query(arr, blocks,0 , n-1 , n) << "\n"; 
    


    return 0;


}
