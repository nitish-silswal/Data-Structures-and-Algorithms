//======================== NITISH SILSWAL  ========================== \\

#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long
#define pb                  push_back
#define mp                  make_pair
#define foritr(x)           for(auto it = x.begin() ; it!= x.end() ;  it++)
#define fo(i , n)           for(int i=0 ; i <n ; i++)
#define foo(i,k,n)          for(int i=k ; i<n ; i++)
#define sortt(x)            sort(x.begin() , x.end())
#define print(x)            cout << x << "\n"  
#define fs                  first
#define sec                 second
#define MOD                 int(1e9 + 7)
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
#define umap                unordered_map
#define uset                unordered_set
#define present(x,y)        x.find(y) != x.end()
#define deb(x)              cout<<#x<<" is "<<x<<"\n";  
#define setP(num , x)       cout<<fixed<<setprecision(x)<<num<<"\n"
#define ld                  long double
#define printclock          cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
ll modInverse(ll n){return power(n , MOD-2 , MOD);}

vector<pair<int, int>> traverse_4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<pair<int, int>> traverse_8 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<pair<int, int>> traverse_knight = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}};



//=================VARIABLES  =====================\\



//============== HELPER FUNCTIONS ===================\\



//RETURNS INDICES (NOT ELEMENTS)
vector<int> getNSL(vector<int> &arr)
{
    stack<int>st;
    vector<int>NSL ;
    int n = arr.size();
    for(int i=0 ; i < n  ; ++i)
    {
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        
        if(st.empty())
            NSL.push_back(-1);
        
        else
            NSL.push_back(st.top());
            
        st.push(i);
    }
    
    return NSL;
    
}


//RETURNS INDICES (NOT ELEMENTS)
vector<int> getNSR(vector<int> &arr )
{
    int n = arr.size();
    stack<int>st;
    vector<int>NSR;
    
    for(int i=n-1 ; i>=0 ; i--)
    {
        while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        
        if(st.empty())
            NSR.push_back(n);
        
        else
            NSR.push_back(st.top());
        
        st.push(i);
    }
    
    reverse(NSR.begin() , NSR.end());
    return NSR;
    
}


//================= MAIN FUNCTION   ==================\\



int main(void)
{

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif  

    fastio()
    
    int n;
    cin >> n;
    vector<int>arr(n);
    fo (i,n) cin >> arr[i];

    vector<int>NSL = getNSL(arr);

    for(int x : NSL)
        cout << x << " ";

    cout << "\n";

    return 0;

}