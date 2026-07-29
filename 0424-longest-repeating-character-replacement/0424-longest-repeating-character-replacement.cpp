class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();

        int freq[26] = {0};

        int left = 0;
        int right = 0;

        int maxFreq = 0;
        int maxLen = 0;

        while (right < n) {

            // Include current character in the window
            freq[s[right] - 'A']++;

            // Update maximum frequency
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Shrink window if it becomes invalid
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update answer
            maxLen = max(maxLen, right - left + 1);

            // Expand window
            right++;
        }

        return maxLen;
    }
};