class Solution {
public:
    // using hashing
    void func(int col,vector<vector<string>>&ans,vector<string>&board,vector<int>&left,vector<int>&ldiagonal,vector<int>&udiagonal,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row < n;row++){
            if(left[row] == 0 && ldiagonal[row+col] == 0 && udiagonal[n-1+col-row] == 0){
                board[row][col] = 'Q';
                left[row] = 1;
                ldiagonal[row+col] = 1;
                udiagonal[n-1+ col - row] = 1;
                func(col+1,ans,board,left,ldiagonal,udiagonal,n);
                board[row][col] = '.';
                left[row] = 0;
                ldiagonal[row+col] = 0;
                udiagonal[n-1+ col - row] = 0;
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        vector<int>left(n,0);
        vector<int> ldiagonal(2*n-1);
        vector<int> udiagonal(2*n-1);
        func(0,ans,board,left,ldiagonal,udiagonal,n);
        return ans;
    }
};
