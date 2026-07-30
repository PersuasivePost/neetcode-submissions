class MinStack {
   public:
    stack<int> sat;
    MinStack() {
        
    }

    void push(int val) { sat.push(val); }

    void pop() { sat.pop(); }

    int top() {
        sat.top();
        return sat.top();
    }

    int getMin() {
        int mn = INT_MAX;
        stack<int> temp;
        while (!sat.empty()) {
            mn = min(mn, sat.top());
            temp.push(sat.top());
            sat.pop();
        }

        while (!temp.empty()) {
            sat.push(temp.top());
            temp.pop();
        }

        return mn;
    }
};
