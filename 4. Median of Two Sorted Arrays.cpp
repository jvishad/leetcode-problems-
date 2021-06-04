class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m1 = nums1.size();
        int m2 = nums2.size();
        bool flag = false;
        if((m1+m2)%2 == 0){
            flag = true;
        }
        if(m1 == 0){
            if(flag == false){
                double ans = nums2[m2/2];
                return ans;
            }
            else{
                double ans = nums2[m2/2 -1] + nums2[m2/2];
                return ans/2.0;
            }
        }
        
        if(m2 == 0){
            if(flag == false){
                double ans = nums1[m1/2];
                return ans;
            }
            else{
                double ans = nums1[m1/2 -1] + nums1[m1/2];
                return ans/2.0;
            }
        }
        
        if(m1 > m2){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int l1 = 0,l2= 0;
        int r1 = 0,r2 = 0;
        int low = 0;
        int high = nums1.size();
        // int left = (nums1.size()+nums2.size())/2;
        // int right = nums1.size() + nums2.size() - left;
        
        while(low <= high){
            int cut1 = low + (high-low)/2;
            int cut2 = (nums1.size()+nums2.size()+1)/2 - cut1;
            cout << cut1 << " " << cut2 << endl;
            l1 = cut1 == 0 ? INT_MIN:nums1[cut1-1];
            l2 = cut2 == 0 ? INT_MIN:nums2[cut2-1];
            r1 = cut1 == nums1.size() ? INT_MAX:nums1[cut1];
            r2 = cut2 == nums2.size() ? INT_MAX:nums2[cut2];
            cout << l1 << endl;
            cout << l2 << endl;
            cout << r1 << endl;
            cout << r2 << endl;
            
            if(l1 <= r2 && l2 <= r1){
                if(flag == true){
                    double ans = max(l1,l2) + min(r1,r2);
                    return ans/2.0;
                }
                if(flag == false){
                    double ans = max(l1,l2);
                    return ans;
                }
            }
            else if(l1 > r2){
                    high = cut1-1;
                }
                
                else{
                    low = cut1+1;
                }
            }
            
        return 0.00;
    }
};
