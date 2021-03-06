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
    
    int findLeftHeight(TreeNode* curr){
        
        int h = 0;
        while(curr){
            h++;
            curr = curr->left;
        }
        
        return h;
    }
    
    int findRightHeight(TreeNode* curr){
        
        int h = 0;
        while(curr){
            h++;
            curr = curr->right;
        }
        
        return h;
    }
    
    int countNodes(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);
        
        if(leftHeight==rightHeight){
            return (1<<leftHeight) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
