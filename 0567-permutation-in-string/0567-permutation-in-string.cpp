class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();
        if(m < n) return false;

        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);

        //get the freq table of smaller string first.
        for(char i : s1){
            s1_freq[i - 'a']++;
        }

        //sliding window's size should be the size of s1.
        int i = 0;
        int j = 0;
        while(j < m){
            s2_freq[s2[j] - 'a']++;

            if(j - i + 1 > n) {
                s2_freq[s2[i] - 'a']--;    //left wala hatana hai ie. i
                i++;
            }
            if(s2_freq == s1_freq) return true;
            j++;
        }
        return false;
    }
};