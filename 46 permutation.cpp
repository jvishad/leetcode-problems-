class Solution {
public:

    // using additional space may cost an additonal space complexity of O(n)+ O(n)
    // time complexity is O(n!)*n
    // recursive approach
    void function(vector<vector<int>> &ans,vector<int>&nums,vector<int> &ds,vector<int> frequency_array){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(frequency_array[i] == 0){
                frequency_array[i] = 1;
                ds.push_back(nums[i]);
                function(ans,nums,ds,frequency_array);
//                 used for backtracking
                frequency_array[i] = 0;
                ds.pop_back();
            }
        }

    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        vector<int> frequency_array(nums.size(),0);
        function(ans,nums,ds,frequency_array);
        return ans;
    }
};