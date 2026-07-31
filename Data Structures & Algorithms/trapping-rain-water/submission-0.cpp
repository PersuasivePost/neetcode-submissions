class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int right = n - 1;
        int left = 0, left_max = 0, right_max = 0, total_water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                left_max = max(left_max, height[left]);
                total_water += left_max - height[left];

                left++;
            } else {
                right_max = max(right_max, height[right]);
                total_water += right_max - height[right];

                right--;
            }
        }

        return total_water;
    } 
};
