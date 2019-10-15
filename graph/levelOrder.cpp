/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
map<int, vector<int> > mp;
 
void traverse(TreeNode* root, int d)
{
    if(!root)
        return;
 
    mp[d].push_back(root->val);
 
    traverse(root->left, d+1);
    traverse(root->right, d+1);
} 
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    mp.clear();
 
    traverse(A, 0);
 
    vector<vector<int> > res;
 
    for(auto x : mp)
        res.push_back(x.second);
 
    return res;
}
