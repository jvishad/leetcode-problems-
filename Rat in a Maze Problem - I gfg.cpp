class Solution{
    public:
    bool valid(vector<vector<int>> &m, int n,int i,int j){
        if(i >= 0 && i<n && j>=0 && j<n && m[i][j] == 1){
            return true;
        }
        return false;
    }
    
    void func(int i,int j,vector<vector<int>> &m, int n,vector<string>&vec,string &s){
        if(i == n-1 && j == n-1){
            vec.push_back(s);
            // s = "";
            return;
        }
        
        m[i][j] = 0;
        
         if(valid(m,n,i+1,j) == true){
            s.push_back('D');
            func(i+1,j,m,n,vec,s);
            s.pop_back();
        }
        
         if(valid(m,n,i,j-1) == true){
            s.push_back('L');
            func(i,j-1,m,n,vec,s);
            s.pop_back();
        }
        
        
        if(valid(m,n,i,j+1) == true){
            s.push_back('R');
            func(i,j+1,m,n,vec,s);
            s.pop_back();
        }
        
        if(valid(m,n,i-1,j) == true){
            s.push_back('U');
            func(i-1,j,m,n,vec,s);
            s.pop_back();
        }
        
        m[i][j] = 1;
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> vec;
        string s = "";
        if(m[0][0] == 0 || m[n-1][n-1] == 0){
            return vec;
        }
        func(0,0,m,n,vec,s);
        // sort(vec.begin(),vec.end());
        return vec;
    }
};
