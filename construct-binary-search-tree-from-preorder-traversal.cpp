/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* constructBST(int &i, int n, vector<int>& preorder, int b){
        
        if(i==n || preorder[i]>b){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = constructBST(i,n,preorder,root->val);
        root->right = constructBST(i,n,preorder,b);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n = preorder.size();
        int i = 0;
        return constructBST(i,n,preorder,INT_MAX);
    }
};
