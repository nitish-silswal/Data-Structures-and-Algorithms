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

const int maxN = int(1e5) + 5;
const int inf = int(1e7);

vector<pair<int , int> >g[maxN];
int dist[maxN];




//============== HELPER FUNCTIONS ===================\\

void dijikstra(int src)
{
    dist[src] = 0;
    priority_queue<pii , vector<pii> , greater<pii>>pq;
    pq.push({0 , src});

    while(!pq.empty())
    {
        int currNode = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();


        for(pair<int , int> &edge : g[currNode])
        {
            if(edge.second + currDist < dist[edge.first])
            {
                dist[edge.first] = edge.second + currDist;
                pq.push({dist[edge.first] , edge.first});
            }
        }

    }

}



//================= MAIN FUNCTION   ==================\\



int main(void)
{

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif  

    int n , m;
    cin >> n >> m;

    for(int i=0 ;i<=n ; i++)
    {
        g[i].clear();
        dist[i] = inf;
    }

    while(m --)
    {
        int u , v , wt;
        cin >> u >> v >> wt;
        g[u].push_back({v , wt});
    }  

    dijikstra(2);


    for(int i=1 ; i<=n  ; i++)
      cout << i << " -> " << dist[i] << "\n";


    return 0;

}