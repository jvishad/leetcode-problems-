class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();
        int l = 0;
        int r = n-1;
        while(l < r){
            int mid = (l+r)/2;
            if(mid%2==0){
                if(mid-1 >= 0 && a[mid] == a[mid-1]){
                    r = mid-1;
                }
                else if(mid+1 < n && a[mid] == a[mid+1]){
                    l = mid+1;
                }
                else{
                    return a[mid];
                }
            }
            else{
                if(mid-1 >= 0 && a[mid] == a[mid-1]){
                    l = mid+1;
                }
                else if(mid+1 <  n && a[mid] == a[mid+1]){
                    r = mid-1;
                }
                else{
                    return a[mid];
                }
            }
        }
        return a[l];
    }
};
