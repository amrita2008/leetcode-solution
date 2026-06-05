class Solution {
public:

    int atMost(vector<int>& nums, int k){

        int l = 0;
        int odd = 0;
        int ans = 0;

        for(int r=0;r<nums.size();r++){

            odd += nums[r] % 2;

            while(odd > k){
                odd -= nums[l] % 2;
                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        return atMost(nums,k) - atMost(nums,k-1);
    }
};