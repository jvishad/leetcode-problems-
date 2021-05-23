class Solution {
public:
    vector<string> ans;
    vector<string> fun(string digits,int idx,string s,unordered_map<int,string> mp){

        if(idx >= digits.size()){
           if(s == ""){
               return ans;
           }
            ans.push_back(s);
            return ans;
        }

        int n = digits[idx]-'0';
        for(int i=0;i<mp[n].size();i++){
            char c = mp[n][i];
            fun(digits,idx+1,s+c,mp);
        }
        // ans.push_back(s);
        return ans;
    }


    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        unordered_map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        if(digits.size() == 0){
            return {};
        }
        ans = fun(digits,0,"",mp);
        return ans;
    }
};