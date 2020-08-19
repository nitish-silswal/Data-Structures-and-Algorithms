#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define pb                  push_back
#define mp                  make_pair
#define foritr(x)           for(auto it = x.begin() ; it!= x.end() ;  it++)
#define fo(i , n)           for(int i=0 ; i <n ; i++)
#define foo(i,k,n)	    	for(int i=k ; i<n ; i++)
#define sortt(x)            sort(x.begin() , x.end())
#define fs                  first
#define sec                 second
#define MOD                 1000000007
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
#define println(x)			cout << x << "\n";
#define print(x)            cout << x << " ";
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

// ====================================================
const int N = 1e5 + 1;
int parent[N];
int R[N];

int find(int n) // Path Compression Part
{
    if(n == parent[n]) 
        return n;
    else
    {
        int x = find(parent[n]); // updates all the parent pointers to be the key of the set along the way
        parent[n] = x;
        return x;                // finally returns the key of the set -> next time this operation will take O(1) time... 
                                 // coz of pre-computation here in this step.
    }
    
}

void Union(int a , int b)
{
    a = find(a);
    b = find(b);

    if(a == b) // both elements in the same set
        return ;
    
    if(R[a] > R[b]) // a is larger tree (has greater max path length)
    {
        parent[b] = a;
        R[a] += R[b];
    }

    else
    {
        parent[a] = b;
        R[b] += R[a];
    }
}

void initialise()
{
    for(int i=0 ; i<N ; i++)
    {   
        // because single element in each set initially
        parent[i] = i;
        R[i] = 1;
    }
}



// ================= MAIN FN ======================================
int main(void)
{   
    fastio()
    //  #ifndef ONLINE_JUDGE
    // freopen("/home/nitish/Desktop/inp.txt", "r", stdin);
    // freopen("/home/nitish/Desktop/out.txt", "w", stdout);
    // #endif

    int n , m;
    cin >> n >> m;
    
    initialise();

    while(m--)
    {
        int u , v;
        cin >> u >> v;
        Union(u , v); // merge 
    } 

    for(int i=1 ; i<=n ; i+=1) // testing :p
        cout << parent[i] << " ";
    

    

    return 0;
}