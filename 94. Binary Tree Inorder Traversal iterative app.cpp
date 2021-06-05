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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL){
            return {};
        }
       TreeNode* curr = root;
        stack<TreeNode*> st;
        st.push(curr);
        curr = curr->left;
        while(st.size()>0 || curr!=NULL){
            while(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;

            
        }
        return ans;
    }
};
