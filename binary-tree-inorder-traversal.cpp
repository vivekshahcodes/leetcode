//Recursion
//TC - O(n)
//SC - O(n) for skew trees

class Solution {
public:
    
    void helper(TreeNode* curr, vector<int>& v){
        
        if(curr->left) helper(curr->left,v);
        v.push_back(curr->val);
        if(curr->right) helper(curr->right,v);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> v;
        if(root!=NULL) helper(root,v);
        return v;
    }
};


//Iterative
//TC - O(n)
//SC - O(n) for skew trees

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> s;
        TreeNode* curr = root;
        vector<int> inorder;
        
        while(true){
            if(curr!=NULL){
                s.push(curr);
                curr = curr->left;
            }else{
                if(s.empty()) break;
                curr = s.top();
                s.pop();
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return inorder;
    }
};
