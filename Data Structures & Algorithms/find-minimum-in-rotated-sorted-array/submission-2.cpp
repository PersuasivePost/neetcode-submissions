class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans = nums[0];
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            if (nums[left] < nums[right]) {
                ans = min(ans, nums[left]);
                break;
            }
            int m = left + (right - left) / 2;
            ans = min(ans, nums[m]);

            if (nums[m] >= nums[left]) {
                left = m + 1;
            } else {
                right = m - 1;
            }
        }
        return ans;
    }
};