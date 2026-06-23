class Solution {
public:
    int fun(vector<int>& weights, int capacity) {
        int days = 1;
        int load = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > capacity) {
                days++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());

        int right = 0;
        for (int w : weights) {
            right += w;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int needed = fun(weights, mid);

            if (needed <= days) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};