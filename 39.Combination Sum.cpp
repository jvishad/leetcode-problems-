class Solution {
public:
    
    void func(int ind,vector<vector<int>> &ans,vector<int>&vec,int t,vector<int>&c,int sz){

        if(ind == sz){
            if(t == 0){
                ans.push_back(vec);
                return;
            }
            else{
                return;
            }
        }
        
        if(t - c[ind]>=0){
            vec.push_back(c[ind]);
        func(ind,ans,vec,t-c[ind],c,sz);
            vec.pop_back();
        }
        func(ind+1,ans,vec,t,c,sz);
        // vec.pop_back();
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> vec;
        sort(c.begin(),c.end());
        int sz = c.size();
        func(0,ans,vec,t,c,sz);
        return ans;
    }
};
