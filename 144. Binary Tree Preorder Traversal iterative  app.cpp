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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        stack<TreeNode*> st;
        TreeNode* curr = root;
        st.push(curr);
        ans.push_back(curr->val);
        curr = curr->left;
        while(curr!=NULL || st.size()>0){
            while(curr!=NULL){
                
                ans.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
                
            }
            if(curr == NULL){
            curr = st.top();
            st.pop();
            curr = curr->right;
            }
        }
        return ans;
    }
};
