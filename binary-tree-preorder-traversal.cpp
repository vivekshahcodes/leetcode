//Recursion

class Solution {
public:
    void helper(TreeNode* curr, vector<int>& v){ 
        v.push_back(curr->val);
        if(curr->left) helper(curr->left,v);
        if(curr->right) helper(curr->right,v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root!=NULL) helper(root, v);
        return v;
    }
};


//Iterative

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> s;
        s.push(root);
        
        vector<int> preorder;
        if(root==NULL) return preorder;
        
        while(!s.empty()){
            TreeNode* curr = s.top();
            s.pop();
            preorder.push_back(curr->val);
            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
        }
        
        return preorder;
    }
};
