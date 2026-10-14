class Solution {
public:
    int smallestValue(int n) {
        while (true) {
            int temp = n, sum = 0;

            for (int i = 2; i * i <= temp; i++) {
                while (temp % i == 0) {
                    sum += i;
                    temp /= i;
                }
            }

            if (temp > 1) sum += temp;

            if (sum == n) return n;

            n = sum;
        }
    }
};