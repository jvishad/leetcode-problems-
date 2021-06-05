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
        vector<vector<int>> vec;
        if(root == NULL){
            return vec;
        }
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int sz = que.size();
            TreeNode* qq;
            while(sz--){
                qq = que.front();
                que.pop();
                ans.push_back(qq->val);
                if(qq->left!=NULL){
                    que.push(qq->left);
                }
                if(qq->right!=NULL){
                    que.push(qq->right);
                }
            }
            vec.push_back(ans);
            ans.clear();
        }
        return vec;
    }
};
