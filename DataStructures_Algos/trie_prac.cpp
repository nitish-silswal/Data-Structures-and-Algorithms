#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define pb                  push_back
#define mp                  make_pair
#define foritr(x)           for(auto it = x.begin() ; it!= x.end() ;  it++)
#define fo(i , n)           for(int i=0 ; i <n ; i++)
#define foo(i,k,n)			for(int i=k ; i<n ; i++)
#define sortt(x)            sort(x.begin() , x.end())
#define fs                  first
#define sec                 second
#define MOD                 998244353
#define MAX                 1e9
#define MIN                 -1e9
#define fastio()            ios_base::sync_with_stdio(0);cin.tie();cout.tie(0);
#define pii                 pair<int,int>
#define tests()              int testcases;cin>>testcases;while(testcases--)
#define vi                  vector<int>
#define vll                 vector<ll>
#define vvi                 vector<vi>
#define pll                 pair<ll,ll>
#define pii                 pair<int,int>
#define all(p)              p.begin(),p.end()
#define deb(x)              cout<<#x<<" "<<x<<"\n";  
#define setP(num , x)         cout<<fixed<<setprecision(x)<<num<<"\n"
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

#define ALPHABET_SIZE 26

struct TrieNode
{
    bool isEndOfWord;
    TrieNode* children[ALPHABET_SIZE];

    TrieNode()
    {
        this->isEndOfWord = false;
        for(int i=0 ; i<ALPHABET_SIZE ; i++)
            this->children[i] = NULL;
    }
};


void insert(TrieNode* &root , string key)
{
    TrieNode* crawler = root;
    for(char ch : key){
        int index = ch - 'a';
        if(crawler->children[index] == NULL)
            crawler->children[index] = new TrieNode();
        
        crawler = crawler->children[index];

    }

    crawler->isEndOfWord = true;
}

bool search(TrieNode* root , string key)
{
    if (key.length() == 0) return false;
    TrieNode* crawler = root;
    for(char ch :  key)
    {
        int index = ch - 'a';
        if(crawler->children[index] == NULL)    
            return false;
        
        crawler = crawler->children[index];
        
    }

    return (crawler->isEndOfWord);
}

TrieNode* deleteWord(TrieNode* &root , string key)
{
    
}


int main(void)
{   
    TrieNode* root = new TrieNode();

    vector<string>arr = {"the" , "app", "apple" , "abc" ,  "their" , "bye"};
    for(string ss : arr)
        insert(root , ss); 

    while(true)
    {
        string s;
        cin >> s;
        if(search(root , s))    
            cout << "YES\n";

        else
            cout << "NO\n";
    }


    return 0;
}