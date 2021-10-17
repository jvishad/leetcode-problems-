/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* helper(vector<int> &vec,int st,int end){
    if(vec.size() == 0){
        return NULL;
    }

    if(st > end){
        return NULL;
    }

    int mid = (st + end)/2;
    TreeNode* root = new TreeNode(vec[mid]);
    root->left = helper(vec,st,mid-1);
    root->right = helper(vec,mid+1,end);
    return root;

}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> vec;
    while(A!= NULL){
        vec.push_back(A->val);
        A = A->next;
    }

    int st = 0;
    int n = vec.size();
    int end = n-1;
    return helper(vec,st,end);

}
