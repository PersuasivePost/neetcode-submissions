class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> temp;
        vector<int> results(n, 0);

        for (int i = 0; i < n; i++) {
            while (!temp.empty() && temperatures[i] > temperatures[temp.top()]) {
                int prev = temp.top();
                temp.pop();
                results[prev] = i - prev;
            }
            temp.push(i);
        }

        return results;
    }
};
