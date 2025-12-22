class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        int r=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[r++]=nums[i];
            }
        }
        for(;r<n;r++){
            nums[r]=0;
        }

    }
};