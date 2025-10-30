class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_l = 0, max_r = 0, max_area = 0;

        while (left < right) {
            int container_h = (height[left] < height[right]) ? height[left] : height[right];
            int container_w = right - left;
            int area = container_h * container_w;

            if (area > max_area) {
                max_area = area;
                max_l = left;
                max_r = right;
            }

            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return max_area;
    }
};