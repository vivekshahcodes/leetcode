/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void findParents(TreeNode* node, unordered_map<TreeNode*,TreeNode*>& p){
        
        queue<TreeNode*> q;
        q.push(node);
        
        while(!q.empty()){
            
            int len = q.size();
            for(int i=0;i<len;i++){
                
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left){
                    p[curr->left] = curr;
                    q.push(curr->left);
                }
                
                if(curr->right){
                    p[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*> p;
        unordered_map<TreeNode*,bool> visited;
        findParents(root,p);
        
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        
        int d = 0;
        
        while(!q.empty()){
            
            if(d==k){
                break;
            }
            
            int len = q.size();
            for(int i=0;i<len;i++){
                
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                
                if(p[curr] && !visited[p[curr]]){
                    q.push(p[curr]);
                    visited[p[curr]] = true;
                }
                
            }
            
            d++;
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        
        return ans;
    }
};
