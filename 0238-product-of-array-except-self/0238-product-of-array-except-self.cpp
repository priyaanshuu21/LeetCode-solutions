class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        int leftprod = 1;
        for(int i = 0; i < nums.size(); i++){
            answer[i] = leftprod;  //add the leftprod to that place
            leftprod = leftprod * nums[i];  //store current on leftprod for the next iteration
        }

        int rightprod = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            answer[i] = answer[i] * rightprod;   //added the right prod to its place. but there is already an element present there. so multiply by it.
            rightprod = rightprod * nums[i];   //storing the current value to right prod for the prev.
            
        }
        return answer;
    }
};
