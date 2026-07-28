class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> count;
        for (auto num : nums) {
            count[num]++;
        }   
        
        priority_queue <pair <int, int>> pq;
        
        for (auto p : count) {
            pq.push(make_pair(p.second, p.first));
        }

        vector<int> answer;
        while (k--) {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};
