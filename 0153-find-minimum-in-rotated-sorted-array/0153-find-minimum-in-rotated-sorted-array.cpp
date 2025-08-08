class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid, st=0, end=nums.size()-1;
        while(st<=end)
        {
            mid = st + (end - st)/2;

            if(mid!=0 && nums[mid-1]>nums[mid]) return nums[mid];
            else if(nums[mid]<nums[end]) end = mid-1;
            else st = mid+1;
        }
        if(nums[0]<= nums[nums.size()-1]) return nums[0];
        return -1;
    }
};