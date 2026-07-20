class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Step 1: Binary search to find the correct row
        int top = 0;
        int bottom = rows - 1;

        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;

            if (target < matrix[mid][0]) {
                bottom = mid - 1;
            }
            else if (target > matrix[mid][cols - 1]) {
                top = mid + 1;
            }
            else {
                // Step 2: Binary search within that row
                int left = 0;
                int right = cols - 1;

                while (left <= right) {
                    int m = left + (right - left) / 2;

                    if (matrix[mid][m] == target)
                        return true;
                    else if (matrix[mid][m] < target)
                        left = m + 1;
                    else
                        right = m - 1;
                }

                return false;
            }
        }

        return false;
    }
};