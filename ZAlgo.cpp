//======================== _/\_ NITISH SILSWAL _/\_  ========================== 
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
#define tests()             int testcases;cin>>testcases;while(testcases--)
#define vi                  vector<int>
#define vll                 vector<ll>
#define vvi                 vector<vi>
#define pll                 pair<ll,ll>
#define pii                 pair<int,int>
#define all(p)              p.begin(),p.end()
#define deb(x)              cout<<#x<<" "<<x<<"\n";  
#define setP(num , x)       cout<<fixed<<setprecision(x)<<num<<"\n"
#define found(x , y)        x.find(y) != x.end()
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

vector<int> calculateZ(string input)
{
    vector<int>Z(input.length());
    Z[0] = 0;                           // not important -> can put in any value
    int left = 0 , right = 0;           // left and right bound of the Z array

    for(int k = 1 ; k  < input.length() ; ++k)
    {
        // if gone outside the box , reset right and left to k
        if(k > right)
        {
            left = right = k;
            while(right < input.length() && input[right] == input[right-left])
                right++;
            
            Z[k] = right - left;
            right--;
        }

        // operating inside the Z box now
        else 
        {
            int k1 = k - left;  
            // If value doesn't stretch till right boundary , then just copy it.    
            if(Z[k1] < right - k + 1)
                Z[k] = Z[k1];            

            else // Try to see if there are more matches
            {
                left = k;
                while(right < input.length() &&  input[right] == input[right - left])   
                    right++;
                
                Z[k] = right - left;
                right--;
            }            
        }
    } 
    
    return Z;
}


vector<int> matchPattern(string text , string pattern)
{
    string newString = pattern + "$" + text;
    vector<int>Z = calculateZ(newString);


    vector<int>res;
    for(int i=0 ; i<Z.size() ; i++)
    {
        if(Z[i] == pattern.length())
            res.push_back(i - pattern.length() - 1);
    }

    return res;

}

int main(void)
{           
    // freopen("/home/nitish/Desktop/inp.txt" , "r" , stdin);
    // freopen("/home/nitish/Desktop/out.txt" , "w" , stdout);

    string s ,str;
    cin >> s >> str;

    vector<int>matchPositions = matchPattern(s , str);

    if(matchPositions.size() == 0)
    {
        cout << "NO MATCHES\n";
        return 0;
    }


    for(int pos :  matchPositions) 
        cout << pos << "\n";

    

    int m = str.length();
    for(int x : matchPositions)
    {
        cout << s.substr(x, m) << "\n";
    }

    return 0;
}
