class Solution {
public:
    string smallestPalindrome(string s) {

        map<char,int> mp;

        for(char c : s)
            mp[c]++;

        string left = "";
        char middle = '\0';

        for(auto it : mp){

            if(it.second % 2 == 1)
                middle = it.first;

            left += string(it.second / 2, it.first);
        }

        string right = left;
        reverse(right.begin(), right.end());

        if(middle != '\0')
            return left + middle + right;

        return left + right;
    }
};