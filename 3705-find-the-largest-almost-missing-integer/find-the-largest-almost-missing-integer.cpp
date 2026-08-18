class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        // Case 1: k == 1
        if (k == 1) {
            int max_val = -1;
            for (auto& [val, count] : freq) {
                if (count == 1) {
                    max_val = max(max_val, val);
                }
            }
            return max_val;
        }

        // Case 2: k == n
        if (k == n) {
            int max_val = -1;
            for (int x : nums) {
                max_val = max(max_val, x);
            }
            return max_val;
        }

        // Case 3: 1 < k < n
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};