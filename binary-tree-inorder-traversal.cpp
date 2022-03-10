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
    
    void helper(TreeNode* curr, vector<int>& v){
        
        if(curr->left){
            helper(curr->left,v);
        }
        
        v.push_back(curr->val);
        
        if(curr->right){
            helper(curr->right,v);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> v;
        
        if(root!=NULL){
            helper(root,v);
        }
        
        return v;
    }
};
