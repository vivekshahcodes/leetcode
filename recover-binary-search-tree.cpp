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
    
private:
    TreeNode *first, *adj, *prev, *second;
    
public:
    
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        
        inorder(root->left);
        
        if(prev!=NULL && (root->val<prev->val)){
            
            if(first==NULL){
                first = prev;
                adj = root;
            }else{
                second = root;
            }
        }
        
        prev = root;
        inorder(root->right);
        
    }
    
    void recoverTree(TreeNode* root) {
        first = adj = second = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first&&second){
            swap(first->val,second->val);
        }else{
            swap(first->val,adj->val);
        }
    }
};
