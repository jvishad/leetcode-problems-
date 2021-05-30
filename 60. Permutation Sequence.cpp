class Solution {
public:
    void func(string &ss,vector<int>&s,int n,int k){
        int fact[n];
        for(int i=0;i<n;i++){
            fact[i] = 1;
        }
    
        for(int i=1;i<n;i++){
            fact[i] = i*fact[i-1];
        }
        k = k-1;
        while(s.size()){
            n-=1;
            int p = k/fact[n];
            ss+=to_string(s[p]);
            s.erase(s.begin() + p);
            k%=fact[n];
            // n-=1;
        }
    }
    
    string getPermutation(int n, int k) {
        vector<int> s;
        for(int i=0;i<n;i++){
            s.push_back(i+1);
        }
        string ss = "";
        func(ss,s,n,k);
        return ss;
    }
};
