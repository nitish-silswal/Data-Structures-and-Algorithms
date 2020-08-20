//======================== NITISH SILSWAL  ========================== \\

#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
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

ll ans = 0;

	
//============== HELPER FUNCTIONS ===================\\

void merge(ll arr[] , int l , int mid , int r)
{
	int n1 = mid-l+1 , n2 = r-mid;
	ll L[n1] , R[n2];

	for(int i=0 ; i<n1 ; i++)
		L[i] = arr[i+l];

	for(int i=0 ; i<n2 ; i++)
		R[i] = arr[mid+1+i];

	int i=0  , j=0 , k = l;

	while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } else { 
        	ans += (n1 - i);		// One extra line
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 


}




void mergeSort(ll arr[] , int l , int r)
{
	if(l >= r) return ;

	int mid = l + (r -l )/2;

	mergeSort(arr , l , mid);
	mergeSort(arr , mid+1 , r);

	merge(arr , l , mid , r);
}



//================= MAIN FUNCTION   ==================\\

int main(void)
{


    fastio()
    tests()
    {
    	int n;
    	cin >> n;
    	ll arr[n];
    	fo(i , n) cin >> arr[i];

    	ans = 0;

    	mergeSort(arr , 0 , n-1);

    	cout << ans << "\n";
    }
 	


    return 0;
}