class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,maxlength=0,r=0,zerocount=0;
        for(int r=0; r<nums.size();r++){
            if(nums[r]==0){
                zerocount++;
            }
            while(zerocount>k){
                if(nums[l]==0){
                    zerocount--;
                }
                l++;
            }
            maxlength=max(maxlength,r-l+1);
        }
        return maxlength;
    }
};