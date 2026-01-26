class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int nums_size = nums.size();
        sort(nums.begin(), nums.end());
        int result = nums[k - 1] - nums[0];

        for (int i = 0; i + k <= nums_size; i++) {
            result = min(result, nums[i + k - 1] - nums[i]);
        }

        return result;
    }
};