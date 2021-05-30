class Solution {
public:
    bool parti(string s){
        int n = s.size();
        int st = 0;
        int en = n-1;
        while(st <= en){
            if(s[st]!=s[en]){
                return false;
            }
            st++;
            en--;
        }
        return true;
    }
    void func(int ind,vector<string>&vec,vector<vector<string>>&ans,string s){
        if(ind == s.size()){
            ans.push_back(vec);
            return;
        }
        
        for(int i=ind;i<s.size();i++){
            if(parti(s.substr(ind,i-ind+1)) == true){
                vec.push_back(s.substr(ind,i-ind+1));
                func(i+1,vec,ans,s);
                
                vec.pop_back();
            }
        }
        
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> vec;
        func(0,vec,ans,s);
        return ans;
    }
};
