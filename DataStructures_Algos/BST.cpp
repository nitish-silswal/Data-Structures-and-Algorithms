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

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x){
		val = x;
		left = NULL , right = NULL;
	}

	TreeNode(){
		TreeNode(0);
	}


};
TreeNode* deleteNode(TreeNode* root , int x);

void inorderPrint(TreeNode* root)
{
	if(root == NULL) return;
	inorderPrint(root->left);
	cout << root->val << " ";
	inorderPrint(root->right);
}


void insert2(TreeNode* &root , int x)
{
	if(root == NULL){
		root = new TreeNode(x);
		return;
	}

	if(x == root->val) return ;

	if(x < root->val)
		insert2(root->left , x);
	
	else
		insert2(root->right , x);
}

TreeNode* insert(TreeNode* root, int x)
{
	if(root == NULL){
		return new TreeNode(x);
	}

	if(root->val == x) return root;
	if(root->val < x)
		root->right = insert(root->right , x);
	
	else
		root->left = insert(root->left , x);
	
	return root;
}

bool search(TreeNode* root , int x)
{
	if(root == NULL) return false;
	
	if(root->val == x) return true;
	if(x <  root->val)
		return search(root->left , x);
	
	else
		return search(root->right , x);	
	
}

int getMaxFromLeft(TreeNode* root)
{
	root = root->left;
	
	while(root->right)
		root = root->right;
	
	return root->val;
	
}

TreeNode* deleteNode(TreeNode* root , int x)
{
	if(root == NULL) return root;
	
	if(root->val < x)
		root->right = deleteNode(root->right , x);
	
	else if(root->val > x)
		root->left = deleteNode(root->left , x);

	else // root->val == x
	{
		if(root->left == NULL && root->right == NULL) // NO CHILDREN
		{
			TreeNode* temp = root;
			delete(temp);
			return NULL;
		}

		if(root->left && root->right) // 2 CHILDREN
		{
			int leftMax = getMaxFromLeft(root);
			root->val = leftMax;
			root->left = deleteNode(root->left , leftMax);
			return root;
		}

		else // 1 CHILD
		{	
			TreeNode* temp = NULL;
			if(root->left){
				temp  = root;
				root = root->left;
			}

			else{
				temp = root;
				root = root->right;
			}

			delete(temp);
			return root;
		}

	}

}


int main(void)
{
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);

	insert2(root , 10);
	insert2(root , -1);

	root = insert(root , 9);
	root = insert(root , 30);
	root = insert(root , -2);

	inorderPrint(root); cout << "\n";

	int x;
	cout << "Enter the node to be deleted\n";
	cin >> x;
	root = deleteNode(root , x);

	inorderPrint(root); cout << "\n";


	return 0;

}

