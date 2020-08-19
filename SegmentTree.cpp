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


void buildTree(int node , int ss , int se) // node -> index in Segment Tree .......... ss & se -> indices in arr
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

int Query(int node , int ss , int se , int qs , int qe)
{
    if(qe < ss || qs > se) // completely outside the range
        return INT_MAX;
    
    if(ss >= qs && se <= qe) // completely inside the range
        return SegTree[node];
    
    // partial overlap -> recurse for both the halves of the segment
    
    int mid = (ss + se) >> 1;
    int left = Query(2*node , ss , mid , qs , qe);
    int right = Query(2*node + 1 , mid+1 , se , qs , qe);

    return left + right;
}


void update(int node , int ss , int se ,  int index , int val)
{
    if(ss == se) // leaf node is hit
    {
        arr[index] = val;
        SegTree[node] = val;
        return ;
    }

    int mid = (ss + se) >> 1;
    if(index <= mid) // update on left subtree
        update(2*node , ss , mid , index , val);
    
    else // update on right subtree
        update(2*node + 1 , mid+1 , se , index , val);

    
    SegTree[node] = SegTree[node << 1] + SegTree[(node << 1) + 1];

}



int main(void)
{
    fastio()
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++) cin >> arr[i];

    buildTree(1 , 0 , n-1);
    
    for(int i=0 ; i<(n << 1) ; ++i) cout << SegTree[i] << " ";  cout << "\n";

    int l , r;
    cin >> l >> r;
    cout << Query(1 , 0 , n-1 , l , r) << "\n";

    cout << "enter update index and value\n";

    int index , val;
    cin >> index >> val;

    update(1 , 0 , n-1 , index,  val);

    for(int i=1 ; i<(n << 1) ; ++i)
        cout << SegTree[i] << " ";
    
    cout << "\n";

    return 0;
}

/*
4
1 2 3 4


*/