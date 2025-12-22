class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int max_w=0;
        while(l<r){
            int h=min(height[l],height[r]);
            int w=r-l;
            max_w=max(max_w,h*w);
            if(height[l]<height[r])l++;
            else r--;
        }
        return max_w;
    }
};