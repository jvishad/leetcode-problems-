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
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        
        stack<TreeNode*> s1,s2;
        s1.push(root);
        while(s1.size()){
            TreeNode* popped_node = s1.top();
            s1.pop();
            s2.push(popped_node);
            if(popped_node->left!=NULL){
                s1.push(popped_node->left);
            }
            if(popped_node->right!=NULL){
                s1.push(popped_node->right);
            }
        }
        while(s2.size()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
       return ans;
    }
};
