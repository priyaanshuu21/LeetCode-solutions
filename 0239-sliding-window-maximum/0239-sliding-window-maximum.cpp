class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int left = 0;
        int right = 0;
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        while(right < n){
            if(dq.empty()) dq.push_back(right);

            //remove all small elements from back (not only one).
            while(!dq.empty() && nums[dq.back()] <= nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);

            //now for left
            //if left increased
            if(dq.front() < left){  //thats why we are storing indices instead of values.
                dq.pop_front();  
            }

            if(right - left + 1 == k){
                ans.push_back(nums[dq.front()]);
                left++;
            }

            right++;
        }
        return ans;
    }
};