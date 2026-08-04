class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;

        int smallest = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < smallest) smallest = nums[i];
        }

        int largest = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > largest) largest = nums[i];
        }

        set<int> s;
        for(int i : nums){
            s.insert(i);
        }

        for(int i = smallest; i <= largest; i++){
            if(!s.count(i)) ans.push_back(i);
        }
        return ans;
    } 
};