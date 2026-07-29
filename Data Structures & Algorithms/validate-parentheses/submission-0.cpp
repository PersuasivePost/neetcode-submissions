class Solution {
public:
    bool isValid(string s) {
        stack<char> sat;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                sat.push(c);
            } else {
                if (sat.empty()) return false;

                if ((c == ')' && sat.top() != '(') || (c == ']' && sat.top() != '[') || (c == '}' && sat.top() != '{')) {
                    return false;
                }

                sat.pop();
            }
        }

        return sat.empty();
    }
};