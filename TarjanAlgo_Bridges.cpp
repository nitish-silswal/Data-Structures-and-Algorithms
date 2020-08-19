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


const int maxN  = 10;
vector<int>g[maxN];
int vis[maxN];
int id[maxN];
int low[maxN];
int timer;

//============== HELPER FUNCTIONS ===================\\


void init(int n)
{
    for(int i=0 ; i<n; i++)
    {
        vis[i] =  false;
        timer = 0;
        id[i] = 0;
        low[i] = 0;
    }
}

void addEdge(int u , int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}


void buildGraph()
{
    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(0,4);
}


void dfs(int curr , int par)
{
    vis[curr] = true;
    id[curr] = timer;
    low[curr] = timer;
    timer++;

    for(int x : g[curr])
    {
        if(x == par) 
           continue;

       // visited the node
       if(vis[x]) // edge node -> child is a backedge
       {    
            low[curr] = min(low[curr] , id[x]);  // Minimise the low time of the current node.
                                                // Make it equal to the id of its ancestor which is 
                                               // causing the formation of a cycle.
       }

       // not visited the node
       else // edge node->child is a forward-edge ..... this "might" be a bridge
       {
            dfs(x , curr);

            if (low[x] > id[curr])
                cout << "This is a bridge " << x << " -> " << curr << "\n";

            low[curr] = min(low[curr] , low[x]);
       }
    }


}


void findBridges_Tarjan()
{
    init(5);

    for(int i=0 ;i<5 ; i++)
    {
        if(!vis[i])
            dfs(i , -1);
    }

}




//================= MAIN FUNCTION   ==================\\



int main(void)
{

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif  

    buildGraph();

    findBridges_Tarjan();    

    return 0;

}