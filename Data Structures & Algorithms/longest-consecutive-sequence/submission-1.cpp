class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set <int> s(nums.begin(), nums.end());
        int max_streak = 0;
        for (int num : s) {
            if (s.count(num-1) == 0) {
                int cur = num;
                int cur_streak = 1;

                while (s.count(cur + 1)) {
                    cur++;
                    cur_streak++;
                }

                max_streak = max(max_streak, cur_streak);
            }
        }

        return max_streak;
    }
};
