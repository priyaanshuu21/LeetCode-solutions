class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            s.insert(nums[i]);
        }

        for(int i : s){
            int current = i;
            if(s.count(i-1)) continue;
            else{
                int length = 1;
                while(s.count(current + 1)){
                    length++;
                    current++;
        }
        answer = max(answer, length);
            }
        }
        return answer;
    }
};