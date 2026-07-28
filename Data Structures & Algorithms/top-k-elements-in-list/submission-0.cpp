class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto p: count){
            pq.push({p.second, p.first});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
