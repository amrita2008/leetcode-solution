class Solution {
public:
    vector<int> getNSL(vector<int> arr, int n) {
        vector<int> NSL(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (s.size() > 0 && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (s.empty()) {
                NSL[i] = -1;
            } 
            else {
                NSL[i] = s.top();
            }
            s.push(i);
        }
        return NSL;
    }
    vector<int> getNSR(vector<int> arr, int n) {
        vector<int> NSR(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (s.size() > 0 && arr[s.top()] > arr[i]) {
                s.pop();
            }
            if (s.empty()) {
                NSR[i] = n;
            } 
            else {
                NSR[i] = s.top();
            }
            s.push(i);
        }
        return NSR;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        long long sum = 0;
        int M = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long ls = i - NSL[i];
            long long lr = NSR[i] - i;

            long long totalways = ls * lr;
            long long totalsum = arr[i] * totalways;
            sum = (sum + totalsum) % M;
        }
        return sum;
    }
};