#include<iostream>
#include<vector>
#include<cmath> 
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<cstring>
#include<stack>
#include<queue>

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5+5;

struct TreeNode{
	int val;
	TreeNode* left; // tree node which has pointer to left child
	TreeNode* right; // tree node with pointer to right child
	TreeNode(int x): val(x), left(NULL), right(NULL){} // initializing val is x , left & right pointer to null
};

void inorder(TreeNode* root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

void preorder(TreeNode* root){
	if(root == NULL)
		return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(TreeNode* root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->val << " ";
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TreeNode* root = new TreeNode(1);  
    root->left = new TreeNode(2);  
    root->right = new TreeNode(3);  
    root->left->left = new TreeNode(4);  
    root->left->right = new TreeNode(5);  

    cout << "inorder" << " ";
   	inorder(root);
   	cout << endl;

   	cout << "preorder" << " ";
   	preorder(root);
   	cout << endl;

   	cout << "postorder" << " ";
   	postorder(root);
   	cout << endl;
}