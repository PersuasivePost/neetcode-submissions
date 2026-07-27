class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> index;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (index.find(diff) != index.end()) {
                return {index[diff], i};
            }

            index[nums[i]] = i;
        } 

        return {};
    }
};
