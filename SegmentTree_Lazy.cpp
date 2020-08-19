//======================== _/\_ NITISH SILSWAL _/\_  ========================== 
#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define pb                  push_back
#define mp                  make_pair
#define foritr(x)           for(auto it = x.begin() ; it!= x.end() ;  it++)
#define fo(i , n)           for(int i=0 ; i <n ; i++)
#define foo(i,k,n)            for(int i=k ; i<n ; i++)
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

const int N = 1e5 + 1;
int arr[N];
int SegTree[2*N];
int lazy[2*N];

// ======================================================================================================

void buildTree(int node , int ss , int se)    // node -> index in Segment Tree .......... ss & se -> indices in arr
{
    if(ss == se){
        SegTree[node] = arr[se];
        return ;        
    }

    int mid = (ss + se)/2;
    buildTree(2*node , ss , mid);
    buildTree(2*node+1 , mid+1, se);

    SegTree[node] = (SegTree[2*node] + SegTree[2*node + 1]);
}


//===========================================================================================================

// Increments each value in the range (if updates are pending) and then queries
int Query(int node , int ss , int se , int qs , int qe)
{   

    if(lazy[node] != 0)                          // update is pending for the current node
    {
        int dx = lazy[node];                     // amount by which the current node is to be incremented / changed
        lazy[node] = 0;                          // reset the update value to 0
        SegTree[node] += (se - ss + 1) * dx;     // update the current node
                                                   
        if(ss != se){                            // push the lazy update to the left and the right child (if node is not a leaf)
            lazy[2*node] += dx;
            lazy[2*node + 1] += dx;
        }
    }


    if(qe < ss || qs > se) // completely outside the range
        return 0;
    
    if(ss >= qs && se <= qe) // completely inside the range
        return SegTree[node];
    
    // partial overlap -> recurse for both the halves of the segment
    
    int mid = (ss + se) >> 1;
    int left = Query(2*node , ss , mid , qs , qe);
    int right = Query(2*node + 1 , mid+1 , se , qs , qe);

    return left + right;
}

//==================================================================================================


// Increments all the values in the given range
void update(int node , int ss , int se , int qs , int qe , int val)
{   
    if(lazy[node] != 0)                  // Pending updates
    {
        int dx = lazy[node];
        lazy[node] = 0;
        SegTree[node] += (se - ss + 1) * dx;

        if(ss != se){
            lazy[2*node] += dx;
            lazy[2*node+1] += dx;
        }
    }

    if(qe < ss || qs > se) 
        return ;

    
    if(ss >= qs && se <= qe)            // Curent updates   
    {
        int dx = (se - ss + 1) * val;
        SegTree[node] += dx;

        if(se != ss)                    // push remaining updates to children and return 
        {
            lazy[2*node] += val;
            lazy[2*node + 1] += val;
        }
        return ;
    }

    // update the left and the right children
    int mid = (ss + se) /2;

    update(2*node , ss , mid , qs , qe , val);
    update(2*node +1 , mid+1 , se , qs , qe , val);


    SegTree[node] = SegTree[2*node] + SegTree[2*node + 1];

   
}

//===================================================================================================

void init(int n)    // INITIALISE
{
    buildTree(1 , 0 , n-1);
    for(int i=1 ; i<(n << 1); i++)
        lazy[i] = 0;
}

//=====================================================================================================

int main(void)
{
    fastio()
    int n;
    cout << "enter the size of the array\n";
    cin >> n;

    cout << "enter array elements\n";
    for(int i=0 ; i<n ; i++) cin >> arr[i];

    init(n);
    
    for(int i=0 ; i<(n << 1) ; ++i) cout << SegTree[i] << " ";  cout << "\n";

    int l , r;
    cout << "enter left and right indices for QUERY\n";
    cin >> l >> r;
    cout << Query(1 , 0 , n-1 , l , r) << "\n";

    cout << "enter update left and right indices .... and update value\n";

    int value;
    cin >> l >> r >> value;

    update(1 , 0 , n-1 , l , r, value);

    for(int i=1 ; i<(n << 1) ; ++i)
        cout << SegTree[i] << " ";
    
    cout << "\n";

    cout << "enter left and right indices for QUERY\n";
    cin >> l >> r;
    cout << Query(1 , 0 , n-1 , l , r) << "\n";




    return 0;
}

/*
4
1 2 3 4


*/