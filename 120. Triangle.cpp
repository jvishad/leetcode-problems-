class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        for(int i= m-2;i>=0;i--){
            for(int j = 0;j<= i;j++){
                if(triangle[i+1][j] > triangle[i+1][j+1]){
                    triangle[i][j]+= triangle[i+1][j+1];
                }
                else{
                    triangle[i][j]+=triangle[i+1][j];
                }
            }
        }
        return triangle[0][0];
    }
};
