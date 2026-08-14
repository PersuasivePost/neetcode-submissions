#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int m = left + (right - left) / 2;

            if (nums[m] == target) {
                return m;
            }

            if (nums[left] <= nums[m]) {

                if (nums[left] <= target && target < nums[m]) {
                    right = m - 1;
                } 
                else {
                    left = m + 1;
                }

            }
            else {
                if (nums[m] < target && target <= nums[right]) {
                    left = m + 1;
                } 
                else {
                    right = m - 1;
                }
            }
        }

        return -1;
    }
};