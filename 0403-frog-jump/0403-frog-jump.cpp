class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if (n == 1) return true;
        if (stones[1] != 1) return false;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }

        vector<unordered_set<int>> dp(n);
        dp[0].insert(0);

        for (int i = 0; i < n; i++) {
            for (int jump : dp[i]) {
                for (int nextJump = jump - 1;
                     nextJump <= jump + 1; nextJump++) {

                    if (nextJump <= 0) continue;

                    int nextPos = stones[i] + nextJump;

                    if (mp.count(nextPos)) {
                        int idx = mp[nextPos];
                        dp[idx].insert(nextJump);
                    }
                }
            }
        }

        return !dp[n - 1].empty();
    }
};