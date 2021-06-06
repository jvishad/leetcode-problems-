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
    
//     more good solution using pair of height and diameter which saves our time in applying recursion again.
    pair<int,int> heightnDiameter(TreeNode* root){
        if(root == NULL){
            pair<int,int> pp;
//             height
            pp.first = 0;
//             diameter
            pp.second = 0;
            return pp;
        }
        
        pair<int,int> leftAns = heightnDiameter(root->left);
        pair<int,int> rightAns = heightnDiameter(root->right);
        int leftheight = leftAns.first;
        int rightheight = rightAns.first;
        int leftdiameter = leftAns.second;
        int rightdiameter = rightAns.second;
        int height = 1 + max(leftheight,rightheight);
        int diameter = max((leftheight+rightheight),max(leftdiameter,rightdiameter));
        pair<int,int> pp;
        pp.first = height;
        pp.second = diameter;
        return pp;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
       pair<int,int> pp = heightnDiameter(root);
        return pp.second;
    }
};
