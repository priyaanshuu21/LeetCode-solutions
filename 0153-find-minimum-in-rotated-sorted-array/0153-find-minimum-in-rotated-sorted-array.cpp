class Solution {
public:
    int findMin(vector<int>& nums) {
        //3 4 5 | 1 2
        int left = 0;
        int right = nums.size() - 1;

        while(left < right){
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]) left = mid+1; //mid cant have the minimum element fs.
            else{
                right = mid;  //dont exculde mid completely. it might have.
            }
        }
        return nums[right];
    }
};