class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int i = 0,l= 0;
        while(l < n){
            if(nums[i] == 1 && nums[i] == nums[l]){
                l++;
            }
            else{
                ans = max(ans,l-i);
                i = l;
                i++;
                l++;
            }
        }
        ans = max(ans,l-i);
        return ans;
    }
};
