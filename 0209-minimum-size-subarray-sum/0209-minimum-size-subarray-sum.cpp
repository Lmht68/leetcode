class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_length = numeric_limits<int>::max();
        int left = 0;
        int curr_sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            curr_sum += nums[right];

            while (curr_sum >= target) {
                if (right - left + 1 < min_length) {
                    min_length = right - left + 1;
                }

                curr_sum -= nums[left];
                left++;
            }
        }

        return min_length != numeric_limits<int>::max() ? min_length : 0;        
    }
};