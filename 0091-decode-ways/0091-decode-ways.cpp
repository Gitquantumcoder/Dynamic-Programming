class Solution {
public:
    int solve(string &s, int i, vector<int> &dp) {
        // Reached the end
        if (i == s.size())
            return 1;
        // Starts with 0 -> invalid
        if (s[i] == '0')
            return 0;
        // Already calculated
        if (dp[i] != -1)
            return dp[i];
        // Take one digit
        int ways = solve(s, i + 1, dp);
        // Take two digits
        if (i + 1 < s.size()) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if (num >= 10 && num <= 26)
                ways += solve(s, i + 2, dp);
        }
        return dp[i] = ways;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);

        return solve(s, 0, dp);
    }
};