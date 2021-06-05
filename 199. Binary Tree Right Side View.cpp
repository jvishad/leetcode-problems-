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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return {};
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int sz = que.size();
            TreeNode* qr;
            while(sz--){
                qr = que.front();
                que.pop();
                if(qr->left!=NULL){
                    que.push(qr->left);
                }
                if(qr->right!=NULL){
                    que.push(qr->right);
                }
            }
            ans.push_back(qr->val);
        }
        return ans;
    }
};
