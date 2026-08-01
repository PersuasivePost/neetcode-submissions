class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> calc;
        int temp = 0;
        int n = tokens.size();
        for (auto &i : tokens) {
            if (i == "+" || i == "-" ||  i == "*" || i == "/") {
                int a = calc.top();
                calc.pop();

                int b = calc.top();
                calc.pop();

                if (i == "+") calc.push(a + b);
                else if (i == "-") calc.push(b - a);
                else if (i == "*") calc.push(a * b);
                else if (i == "/") calc.push(b / a); 
            } else {
                calc.push(stoi(i));
            }
        }

        return calc.top();
    }
};
