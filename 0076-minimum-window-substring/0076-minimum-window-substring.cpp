class Solution {
public:
    string minWindow(string s, string t) {

        int n = t.size();
        int m = s.size();

        if (m < n) return "";

        unordered_map<char, int> mp;

        for (char c : t)
            mp[c]++;

        int i = 0, j = 0;
        int requiredCount = n;

        int minWindow = INT_MAX;
        int start_i = 0;

        while (j < m) {

            if (mp[s[j]] > 0)
                requiredCount--;

            mp[s[j]]--;

            while (requiredCount == 0) {

                if (j - i + 1 < minWindow) {
                    minWindow = j - i + 1;
                    start_i = i;
                }

                mp[s[i]]++;

                if (mp[s[i]] > 0)
                    requiredCount++;

                i++;
            }

            j++;
        }

        return minWindow == INT_MAX ? "" : s.substr(start_i, minWindow);
    }
};