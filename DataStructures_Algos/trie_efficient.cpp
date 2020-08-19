// SPACE EFFICIENT TRIE

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

#define ALPHABET_SIZE 26


struct TrieNode
{   
    bool isEnd;
    unordered_map<char , TrieNode*>map;

    TrieNode()
    {
        this->isEnd = false;
        map.clear();
    }


};

//============== HELPER FUNCTIONS ===================\\

void insert(TrieNode* &root , string s)
{
    TrieNode* curr = root;

    for(char ch : s)
    {
        if(curr->map.find(ch) == curr->map.end())
            curr->map[ch] = new TrieNode();

        curr = curr->map[ch];
    }

    curr->isEnd = true;
    
}


bool search(TrieNode* root , string s)
{
    if(root == NULL){
        cout << "Empty Trie\n";
        return false;
    }

    TrieNode* curr = root;
    for(char ch : s)
    {
        if(curr->map.find(ch) == curr->map.end())
            return false;

        curr = curr->map[ch];
    }

    return  curr->isEnd ;
}


void displayAll(TrieNode* root , string s)
{
    if(root == NULL) return ;

    if(root->isEnd){
        cout << s << "\n";
    }

    for(auto el : root->map)
    {
        char temp = el.first;
        displayAll(root->map[temp] , s + temp);
    }

}



//================= MAIN FUNCTION   ==================\\



int main(void)
{

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif  


    TrieNode * root = new TrieNode();

    int n;
    cin >> n;

    while(n--)
    {
        string s;
        cin >> s;
        insert(root , s);
    }

    // cout << search(root , "apple") << "\n";
    // cout << search(root , "apps") << "\n";
    // cout << search(root , "apples") << "\n";

    displayAll(root , "");

    return 0;


}