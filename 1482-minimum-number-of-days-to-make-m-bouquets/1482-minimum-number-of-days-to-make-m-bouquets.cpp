class Solution {
public:
    bool helperFunction(vector<int> arr, int m, int k, int day)
    {
        int n = arr.size();
        int ans = 0, cnt = 0;

        for(int i = 0; i < n; i++)
        {
            if(arr[i] <= day)
            {
                cnt++;
            }
            else
            {
                ans += (cnt / k);
                cnt = 0;
            }
        }

        ans += (cnt / k);

        return ans >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if(1LL * m * k > 1LL * n)
        {
            return -1;
        }

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = INT_MAX;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(helperFunction(bloomDay, m, k, mid))
            {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};