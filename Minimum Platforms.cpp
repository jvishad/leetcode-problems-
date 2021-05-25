class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.

    
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        int i=1,j=0;
        int cnt = 1;
        int platform = 1;
        
        while(i < n){
            if(arr[i] < dep[j]){
                cnt++;
                platform = max(platform,cnt);
                i++;
            }
            else if(arr[i] > dep[j]){
                j++;
                cnt--;
                platform = max(platform,cnt);
            }
            else{
                i++;
                cnt++;
                platform = max(platform,cnt);
            }
        }
        return platform;
    }
};
