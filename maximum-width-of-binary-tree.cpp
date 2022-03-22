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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        
        int ans = 0;
        
        while(!q.empty()){
            
            int sub = q.front().second;
            int len = q.size();
            int first,last;
            
            for(int i=0;i<len;i++){
                
                TreeNode* curr = q.front().first;
                int v = q.front().second-sub;
                
                q.pop();
                
                if(i==0){
                    first = v;
                }
                
                if(i==len-1){
                    last = v;
                }
                
                if(curr->left){
                    q.push({curr->left,(long long)v*2+1});
                }
                
                if(curr->right){
                    q.push({curr->right,(long long)v*2+2});
                }
            }
            
            ans = max(ans,last-first+1);
        }
        
        return ans;
    }
};
