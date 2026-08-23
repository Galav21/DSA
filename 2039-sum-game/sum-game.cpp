class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sum_diff = 0;
        int q_diff = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') q_diff++;
            else sum_diff += num[i] - '0';
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') q_diff--;
            else sum_diff -= num[i] - '0';
        }

        // Bob wins if 2 * sum_diff == -9 * q_diff
        return (2 * sum_diff != -9 * q_diff);
    }
};