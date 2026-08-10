class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int low = 0, high = n-1;

        // find possible matrix
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (matrix[mid][0] <= target) low = mid + 1;
            else high = mid - 1;
        }

        // no possible row
        if (high < 0) return false;
        int row = high;

        // find in that matrix
        int left = 0;
        int right = matrix[row].size() - 1;

        while (left <= right) {
            int mid = left + (right-left)/2;

            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) left = mid+1;
            else right = mid-1;
        }

        return false;
    }
};
