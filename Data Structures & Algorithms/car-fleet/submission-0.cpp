class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<int> fleet;
        unordered_set<int> temp2;
        for (int i = 0; i < position.size(); i++) {
            int temp = target - position[i];
            auto a = temp / speed[i];
            fleet.push(a);

            // unordered_set<int> temp2;
            while(!fleet.empty()) {
                temp2.insert(fleet.top());
                fleet.pop();
            }
        }

        return temp2.size();
    }
};
