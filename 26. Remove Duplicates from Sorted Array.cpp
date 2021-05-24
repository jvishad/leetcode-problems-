class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 0) {
            return n;
        }
        int i = 1;
        int l = 1;
        while(l < n){
            if(binary_search(nums.begin(),nums.begin()+l,nums[l]) == true){
                l++;
            }
            else{
                nums[i] = nums[l];
                i++;
                l++;
            }
        }
        return i;
        }
};
