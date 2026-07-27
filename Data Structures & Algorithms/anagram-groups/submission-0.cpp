class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0) return {};
        if (strs.size() == 1) return {strs};

        unordered_map <string, vector<string>> map;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }

        vector <vector <string>> result;

        for (auto &it : map) {
            result.push_back(it.second);
        }

        return result;
    }
};
