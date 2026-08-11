class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int maxLen = 0;
        unordered_map<char, int> freq;

        for (int j = 0; j < n; j++) {
            freq[s[j]]++;

            while (freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};