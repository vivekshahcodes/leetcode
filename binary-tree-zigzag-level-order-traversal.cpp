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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> zigzag;
        
        if(root==NULL){
            return {};
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool leftToRight = true;
        
        while(!q.empty()){
            
            int len = q.size();
            vector<int> level(len);
            
            for(int i=0;i<len;i++){
                
                TreeNode* curr = q.front();
                q.pop();
                
                if(leftToRight){
                    level[i] = curr->val;
                }else{
                    level[len-i-1] = curr->val;
                }
                
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
            }
            
            zigzag.push_back(level);
            leftToRight = !leftToRight;
        }
        
        return zigzag;
    }
};
