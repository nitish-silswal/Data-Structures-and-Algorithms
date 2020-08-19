// Strongly connected components in a DIRECTED graph using KOSARAJU's algo


/*
NOTE - We can get the strongly connected components in an undirected graph by using 
       either - 1) Simple dfs     OR    2) Disjoint Set Union Data Structure
*/


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


const int maxN = int(1e5) + 5;  
vector<int>g[maxN];         // Initial / actual graph
vector<int>g2[maxN];        // Graph to store TRANSPOSE of g1
bool vis[maxN];
int n;                      // Number of nodes in the given graph


//============== HELPER FUNCTIONS ===================\\


void dfs(int u , stack<int>&st)   // for filling the stack in step 1 of the algorithm.
{
    vis[u] = 1;

    for(int x : g[u])
    {
        if(!vis[x])
            dfs(x , st);
    }

    st.push(u);             // PUSH the vertex into the stack on completion of its DFS call
}

void dfs2(int u) // final dfs -> for printing the vertices of g2 (transpose  graph) as in the order
                // stored in the stack.
{
    cout << u << " ";
    vis[u]  = 1;

    for(int x : g2[u]){
        if(!vis[x])
            dfs2(x);
    }
}


void transposeGraph()    // Get transpose of the graph 
{
    for(int i=0 ; i<n ; i++)
        g2[i].clear();

    for(int i=0 ; i< n; i++)
    {
        int dest = i;
        for(auto &it : g[i])
        {
            int src = it;
            g2[src].pb(dest);
        }
    }

}

void addEdge(int u, int v)
{
    g[u].pb(v);
}

void buildGraph()  // sample graph
{
    addEdge(1 , 0);
    addEdge(2 , 1);
    addEdge(0 , 2);
    addEdge(0 , 3);
    addEdge(3 , 4);
}

void printGraph(vector<int> adj[])
{
    for(int i=0 ; i<n;  ++i)
    {
        cout << i << " -> ";
        for(auto it : adj[i])
            cout << it << " ";

        cout << "\n";
    }
}


void SCC_Kosaraju(int n) // Strongly connected components
{   
    stack<int>st;
    for(int i=0 ; i<n ; i++)
    {
        if(!vis[i])
            dfs(i , st);
    }

    transposeGraph();

    // NEW GRAPH is now stored in g2 (and not in g) -> so apply dfs2 on g2 to get the vertices in SCCs 


    for(int i=0 ; i<n ; ++i) vis[i] = false;

    int count = 1;

    // Keep popping vertices from the stack and perform dfs2 on them 
    while(!st.empty())  
    {
        if(!vis[st.top()])
        {   
            cout << "SCC" << (count++) << " -> ";
            dfs2(st.top());
            cout << "\n";
        }

        st.pop();
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
    n = 5;
    for(int i=0 ; i<n ; i++) vis[i] = false;


    SCC_Kosaraju(n);
    

    return 0;

}