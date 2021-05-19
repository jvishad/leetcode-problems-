class Solution {
public:

    int dp[1001][1001] = {0};

    string longestPalindrome(string s) {
        string s1 = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            dp[i][i] = true;
        }

//         for(int i= 0;i<n-1;i++){
//             if(s[i] == s[i+1]){
//                 dp[i][i+1] = 1;
//             }
//         }

        int start = 0;
        int len = 1;
        for(int i = 0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                start = i;
                len = 2;
            }
        }


        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        for (int k = 3; k <= n; k++) {
        for (int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;

                if (k > len) {
                    start = i;
                    len = k;
                }
            }
        }
    }

    s1 = s.substr(start,len);
        return s1;






    }
};