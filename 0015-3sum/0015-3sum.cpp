class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) {
            return {};
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int k = 0; k < n - 2; k++) {

            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }

            int i = k + 1;
            int j = n - 1;

            while (i < j) {

                if (nums[i] + nums[j] == -nums[k]) {

                    result.push_back({nums[k], nums[i], nums[j]});

                    i++;
                    j--;

                    // Skip duplicates
                    while (i < j && nums[i] == nums[i - 1]) {
                        i++;
                    }

                    while (i < j && nums[j] == nums[j + 1]) {
                        j--;
                    }
                }
                else if (nums[i] + nums[j] < -nums[k]) {
                    i++;
                }
                else {
                    j--;
                }
            }
        }

        return result;
    }
};