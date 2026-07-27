class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        set<char> st;

        while(right < n){
            if(!st.count(s[right])){
                st.insert(s[right]);
                ans = max(ans, right - left + 1);
                right++;
            }
            else{
                st.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};
//abcabcd