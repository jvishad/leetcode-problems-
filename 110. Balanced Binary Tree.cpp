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
    pair<int,bool> helper(TreeNode* root){
        if(root == NULL){
            pair<int,bool> pp;
//             for height and isbalanced
            pp.first = 0;
            pp.second = true;
            return pp;
        }
        
        pair<int,bool> leftAns = helper(root->left);
        pair<int,bool> rightAns = helper(root->right);
        
        int leftheight = leftAns.first;
        int rightheight = rightAns.first;
        int height = 1 + max(leftheight,rightheight);
        
        bool flag = false;
        if(abs(leftAns.first - rightAns.first) <= 1 && leftAns.second == true && rightAns.second == true){
            flag = true;
        }
        
        pair<int,bool> pp ;
        pp.first = height;
        pp.second = flag;
        return pp;
        
    }
    bool isBalanced(TreeNode* root) {
       if(root == NULL){
           return true;
       }
        
    pair<int,bool> ans = helper(root);
        return ans.second;
    }
};
