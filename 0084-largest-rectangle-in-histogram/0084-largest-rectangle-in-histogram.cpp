class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> premin(heights.size(), 0);
        stack<int> s1;

        for (int i = 0; i < heights.size(); i++) {
            while (s1.empty() == 0 
            && heights[s1.top()] >= heights[i]) {
                s1.pop();
            }
            if (s1.empty() == 1) {
                premin[i] = -1;
            } 
            else {
                premin[i] = s1.top();
            }

            s1.push(i);
        }
        vector<int> sucmin(heights.size(), 0);
        stack<int> s2;

        for (int i = heights.size() - 1; i >= 0; i--) {
            while (s2.empty() == 0 
            && heights[s2.top()] >= heights[i]) {
                s2.pop();
            }
            if (s2.empty() == 1) {
                sucmin[i] = sucmin.size();
            } 
            else {
                sucmin[i] = s2.top();
            }

            s2.push(i);
        }
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {

            int area = heights[i] * (sucmin[i] - premin[i] - 1);

            max_area = max(max_area, area);
        }

        return max_area;
    }
};