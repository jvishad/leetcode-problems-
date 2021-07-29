class Solution {
public:
    void change(int x,int y,char prev,char toUpdate,vector<vector<char>> &board,int n,int m){
        if(x <0 || y < 0 || x >= n || y >= m){
            return;
        }
        
        if(board[x][y] != prev){
            return;
        }
        board[x][y] = toUpdate;
        change(x-1,y,prev,toUpdate,board,n,m);
        change(x,y-1,prev,toUpdate,board,n,m);
        change(x+1,y,prev,toUpdate,board,n,m);
        change(x,y+1,prev,toUpdate,board,n,m);
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = '-';
                }
            }
        }
//         first row
        for(int i=0;i<m;i++){
            if(board[0][i] == '-'){
                change(0,i,'-','O',board,n,m);
            }
        }
//         last row
        for(int i=0;i<m;i++){
            if(board[n-1][i] == '-'){
                change(n-1,i,'-','O',board,n,m);
            }
        }
        
//         first col
        for(int i=0;i<n;i++){
            if(board[i][0] == '-'){
                change(i,0,'-','O',board,n,m);
            }
        }
        
//         last col
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='-'){
                change(i,m-1,'-','O',board,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(board[i][j] == '-'){
                    board[i][j] = 'X';
                }
            }
        }   
    }
};
