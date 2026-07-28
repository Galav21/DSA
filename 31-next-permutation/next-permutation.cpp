class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        
        // Step 1: Find the breakpoint
        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        // Step 2 & 3: Find swap target and swap (if breakpoint exists)
        if(i >= 0){
            int j = n-1;
            while(nums[j] <= nums[i]){
                j--;
            }
            swap(nums[i], nums[j]);
        }
        // Step 4: Reverse the suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};