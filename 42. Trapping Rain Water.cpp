class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int n = height.size();
        if(n==0){
            return 0;
        }
        int r = n-1;
        int left = 0;
        int right = 0;
        int ans = 0;
        while(l < r){
            if(height[l] <= height[r]){
                if(height[l] >= left){
                    left = height[l];
                }
                else{
                    ans+= abs(left-height[l]);
                }
                l++;
            }
            else{
                if(height[r] >= right){
                    right = height[r];
                }
                else{
                    ans+= abs(right-height[r]);
                }
                r--;
            }
        }
        return ans;
    }
};
