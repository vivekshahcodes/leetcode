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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL){
            return {};
        }
        
        queue<TreeNode*> q;
        vector<vector<int>> allLevels;
        
        q.push(root);
        q.push(NULL);
        
        vector<int> level;
        
        while(!q.empty()){
            
            TreeNode* curr = q.front();
            
            if(curr==NULL){
                q.pop();
                allLevels.push_back(level);
                level.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                q.pop();
                level.push_back(curr->val);
                
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        
        return allLevels;
        
    }
};
