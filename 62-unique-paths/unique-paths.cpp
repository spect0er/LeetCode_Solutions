class Solution {
public:
    int helper(int m, int n, int r, int c, vector<vector<int>>&dp){
        if(r >= m || c >= n) return 0;
        if(r == m - 1 && c == n - 1) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        // down
        int down = helper(m,n,r+1,c,dp);
        // right
        int right = helper(m,n,r,c+1,dp);
        dp[r][c] = down + right;
        return dp[r][c];

    }
    int uniquePaths(int m, int n) {
        int count = 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m,n,0,0,dp);
    }
};