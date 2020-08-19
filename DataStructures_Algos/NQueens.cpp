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

#define N 8
int board[N][N];


//============== HELPER FUNCTIONS ===================\\


void printBoard()
{
  for(int i=0  ;i<N ; i++){
    for(int j=0 ; j<N ;j++){
      cout << board[i][j] << " ";
    }

    cout << "\n";
  }
}

bool row_safe(int row)
{
    for(int j=0 ; j<N ; j++)
      if(board[row][j] == 1)
        return false;

      return true;
}

bool col_safe(int col)
{
    for(int i=0 ; i<N ; ++i)
      if(board[i][col] == 1) 
        return false;


    return true;
}

bool diagonal_safe(int row , int col)
{
    int i = row , j = col;

    //LEFT DIAGONAL

    while(i-- && j--)
    {
       if(board[i][j] == 1) return false;
    }

    i = row , j = col;
    while(i < N  && j < N)
    {
      if(board[i++][j++]) return false;
    }

    // RIGHT DIAGONAL
    
    i = row , j = col;
    while(i < N && j >= 0)
    {
      if(board[i++][j--] == 1) return false;
    }

    i = row , j = col;

    while(i >= 0 && j< N)
    {
       if(board[i--][j++] == 1) return false;
    }


    return true;
}



bool isSafe(int row , int col)
{
    if(board[row][col] != 1 && col_safe(col) && row_safe(row) && diagonal_safe(row , col))
      return true;

    return false;
}





bool solveNQueens(int row)
{
    if(row >= N)
      return true;

    for(int col = 0 ; col < N ; col++)
    {
        if(isSafe(row , col))
        {
           board[row][col] = 1;

           if(solveNQueens(row+1))
              return true;

          board[row][col] = 0;
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

    if(solveNQueens(0))
    {
      cout << "YESS \n";
      printBoard();
    }

    else{
      cout << "UN - SOLVABLE\n";
    }


    printclock
    return 0;

}