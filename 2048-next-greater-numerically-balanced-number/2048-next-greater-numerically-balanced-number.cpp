class Solution {
public:
    bool isBalanced(int n) {
        vector<int> freq(10, 0);

        while (n > 0) {
            int digit = n % 10;
            freq[digit]++;
            n /= 10;
        }

        for (int d = 0; d < 10; d++) {
            if (freq[d] > 0 && freq[d] != d) {
                return false;
            }
        }

        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n + 1; i <= 1224444; i++) {
            if (isBalanced(i)) {
                return i;
            }
        }

        return -1;
    }
};