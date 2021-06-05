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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int ans=0;
        while(!que.empty()){
            int sz = que.size();
            TreeNode* tt;
            ans = que.front()->val;
            while(sz--){
                tt = que.front();
                que.pop();
                if(tt->left!=NULL){
                    que.push(tt->left);
                }
                if(tt->right!=NULL){
                    que.push(tt->right);
                }
            }
        }
        return ans;
    }
};
