class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans ="";
        for(int i = 0; i < strs[0].size(); i++){   //iterate on first string
            for(int j = 0; j < n-1; j++){       //iterate on whole vector
                if(strs[j][i] != strs[j+1][i]) return ans;
            }

           ans = ans + strs[0][i];

        }
        return ans;
    }
};