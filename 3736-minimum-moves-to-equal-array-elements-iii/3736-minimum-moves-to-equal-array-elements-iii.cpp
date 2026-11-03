class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx= *max_element(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        for(int x: nums){
            count+=(mx-x);
        }
        return count;
    }
};