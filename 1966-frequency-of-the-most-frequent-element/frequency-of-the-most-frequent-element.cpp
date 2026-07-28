class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        int left= 0;
        long long totalSum = 0;
        int max_freq = 0;

        // Step 2: Expand the right pointer
        for(int right = 0; right < nums.size(); ++right){
            totalSum += nums[right];
            
            // Step 3: Shrink left pointer if ops required exceed k
            while((long long)nums[right] * (right - left + 1) - totalSum > k){
                totalSum -= nums[left];
                left++;
            }
            // Step 4: Keep track of maximum window size
            max_freq = max(max_freq, right- left + 1);
        }
        return max_freq;
    }
};