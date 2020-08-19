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

#define N 9

int grid[N][N] = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 }, 
                   { 5, 2, 9, 1, 3, 4, 7, 6, 8 }, 
                   { 4, 8, 7, 6, 2, 9, 5, 3, 1 }, 
                   { 2, 6, 3, 0, 1, 5, 9, 8, 7 }, 
                   { 9, 7, 4, 8, 6, 0, 1, 2, 5 }, 
                   { 8, 5, 1, 7, 9, 2, 6, 4, 3 }, 
                   { 1, 3, 8, 0, 4, 7, 2, 0, 6 }, 
                   { 6, 9, 2, 3, 5, 1, 8, 7, 4 }, 
                   { 7, 4, 5, 0, 8, 6, 3, 1, 0 } }; 

//============== HELPER FUNCTIONS ===================\\

void printGrid()
{
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; ++j){
            cout << grid[i][j] << " ";
        }

        cout << "\n";
    }
}


bool used_in_row(int row , int num)
{
    for(int j=0 ; j<N ; j++)
    {
        if(grid[row][j] == num) return true;
    }
    return false;
}

bool used_in_col(int col , int num)
{
    for(int i=0 ; i<N ; i++)
    {
        if(grid[i][col] == num) return true;
    }

    return false;
}


bool used_in_box(int row , int col , int num)
{
   int start_row = 3*(row/3) , start_col = 3 * (col/3);

   for(int i = start_row ; i<start_row + 3 ; i++)
   {
        for(int j=start_col ;  j<start_col + 3 ; j++)
        {
            if(grid[i][j] == num)
                return true;
        }
   }

   return false;
}




bool isSafe(int i , int j , int num)
{
    if(!used_in_row(i,num) &&
       !used_in_col(j,num) &&
       !used_in_box(i,j,num) &&
       grid[i][j] == 0)
    {
        return true;
    }

    return false;

}




bool allFilled(int *row , int *col)
{
    for(int i=0 ; i<N ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            if(grid[i][j] == 0){
                *row = i;
                *col = j;
                return false;
            }
        }
    }

    return true;
}



bool solveSudoku()
{   
    int row = -1 , col = -1;
    if(allFilled(&row , &col))
        return true;

    for(int num = 1 ; num <= N ; num++)
    {
        if(isSafe(row , col , num))
        {
            grid[row][col] = num;

            if(solveSudoku())
                return true;


            grid[row][col] = 0;

        }
    }

    return false;
}




//================= MAIN FUNCTION   ==================\\

int main(void)
{

    #ifndef ONLINE_JUDGE
    freopen("/home/nitish/Desktop/inp.txt", "r", stdin);
    freopen("/home/nitish/Desktop/out.txt", "w", stdout);
    #endif  

    if(solveSudoku()){
        cout << "YESSS\n";
        printGrid();
    }

    else{
        cout << "NON - SOLVABLE\n";
    }

    printclock

   return 0;

}