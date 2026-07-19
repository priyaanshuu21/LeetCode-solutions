class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> left(n), right(n);
        stack<int> stk;

        // Previous Smaller Index
        for (int i = 0; i < n; i++) {

            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }

            if (stk.empty())
                left[i] = -1;
            else
                left[i] = stk.top();

            stk.push(i);
        }

        // Clear stack
        while (!stk.empty())
            stk.pop();

        // Next Smaller Index
        for (int i = n - 1; i >= 0; i--) {

            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }

            if (stk.empty())
                right[i] = n;
            else
                right[i] = stk.top();

            stk.push(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};