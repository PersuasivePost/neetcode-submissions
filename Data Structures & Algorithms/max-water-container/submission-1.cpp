class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        vector<int> max;

        while (l < r) {
            int diff = r-l;
            int mini = min(height[l], height[r]);

            int val = diff * mini;
            max.push_back(val);
            
            if (height[l] < height[r]) l++;
            else r--;
        }

        int ans = *max_element(max.begin(), max.end());
        return ans;
    }
};