class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;

        vector<pair<int, double>> cars(n);
        // pair positions with decimal times
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }

        sort(cars.begin(), cars.end());

        int count = 0;
        double time = 0.0;

        // scan backwards from the car closest to the target
        for (int i = n - 1; i >= 0; i--) {
            double car_time = cars[i].second;

            // if this car takes more time than the fleet leader ahead of it, it can never catch up it becomes the leader of a brand new fleet.
            if (car_time > time) {
                time = car_time;
                count++;
            }
        }

        return count;
    }
};
