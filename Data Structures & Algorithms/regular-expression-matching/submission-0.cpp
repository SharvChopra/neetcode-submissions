class Solution {
public:
    int solve(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return 1;

        if (j < 0)
            return 0;
        if (i < 0) {
            if (p[j] == '*')
                return solve(i, j - 2, s, p, dp);

            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (p[j] == '*') {
            int skip = solve(i,j-2,s,p,dp);

            int take = 0;
            if(s[i] == p[j-1] || p[j-1]=='.'){
                take = solve(i-1,j,s,p,dp);
            }

            return dp[i][j] = (skip || take);
        }

        if (s[i] == p[j] || p[j] == '.') {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }

        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, s, p, dp)==1;
    }
};
