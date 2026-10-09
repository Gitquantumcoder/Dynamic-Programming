class Solution {
public:
    pair<int, int> bitCount(const string& st) {
        int zeros = 0, ones = 0;

        for (char ch : st) {
            if (ch == '0') zeros++;
            else ones++;
        }

        return {zeros, ones};
    }

    int solve(vector<string>& strs, int i, int m, int n,
              vector<vector<vector<int>>>& dp) {
        if (i == strs.size()) return 0;

        if (dp[i][m][n] != -1) return dp[i][m][n];

        auto [zeros, ones] = bitCount(strs[i]);

        int include = 0;

        if (zeros <= m && ones <= n) {
            include = 1 + solve(strs, i + 1, m - zeros, n - ones, dp);
        }

        int exclude = solve(strs, i + 1, m, n, dp);

        return dp[i][m][n] = max(include, exclude);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(
            strs.size(),
            vector<vector<int>>(m + 1, vector<int>(n + 1, -1))
        );

        return solve(strs, 0, m, n, dp);
    }
};