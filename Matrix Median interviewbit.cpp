// problem link - https://www.interviewbit.com/problems/matrix-median/
// time complexity - O(log (n*m))*n*log(m) where n is no of rows and m is no of column

int smallerIndexThenCurrentNo(vector<int> &row,int target){
    int low = 0;
    int high = row.size();
    high-=1;
    int mid;
    while(low <= high){
        mid = (low + (high))/2;
        if(row[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
    
}



int Solution::findMedian(vector<vector<int> > &A) {
        int low = 1;
        int high = 1e9;
        int n = A.size();
        int m = A[0].size();
        int mid,cnt;
        while(low <= high){
            cnt = 0;
            mid = (low + high)/2;
            for(int i=0;i<n;i++){
                cnt+= smallerIndexThenCurrentNo(A[i],mid);
                // cnt+=1;
            }
            
            if(cnt > (n*m)/2){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
}
