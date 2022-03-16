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
    
    int helper(TreeNode* node, int &maxSum){
        
        if(node==NULL){
            return 0;
        }
        
        int left = max(0,helper(node->left, maxSum));
        int right = max(0,helper(node->right, maxSum));
        maxSum = max(maxSum, node->val + left + right);
            
        return node->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
};
