class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        int mx = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
            sum += diff[i];
        }

        if (k >= sum) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long operations = 0;

            for (int d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
            }

            if (operations <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int target = low;
        long long ans = 0;
        long long used = 0;

        for (int d : diff) {
            if (d > target) {
                used += d - target;
                d = target;
            }
            ans += 1LL * d * d;
        }

        k -= used;

        for (int i = 0; i < n && k > 0; i++) {
            if (diff[i] > 0) {
                // handled below using the original differences
            }
        }

        // Reconstruct differences and distribute remaining operations.
        vector<int> reduced(n);

        for (int i = 0; i < n; i++) {
            reduced[i] = min(abs(nums1[i] - nums2[i]), target);
        }

        for (int i = 0; i < n && k > 0; i++) {
            if (reduced[i] == target && target > 0) {
                reduced[i]--;
                k--;
            }
        }

        ans = 0;
        for (int d : reduced) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};