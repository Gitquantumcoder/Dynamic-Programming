class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.size();
        long long length = 0;
        int idx = 0;

        while (length < k) {
            if (isalpha(s[idx])) {
                length += 1;
            } else {
                length *= (s[idx] - '0');
            }
            idx++;
        }

        idx--;

        while (idx >= 0) {
            if (isdigit(s[idx])) {
                length /= (s[idx] - '0');
                k %= length;
            } else {
                if (k == 0 || k == length) {
                    return string(1, s[idx]);
                }
                length--;
            }
            idx--;
        }

        return "";
    }
};