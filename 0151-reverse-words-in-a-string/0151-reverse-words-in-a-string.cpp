class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;

        // Remove leading spaces
        while (!s.empty() && s.front() == ' ')
            s.erase(0, 1);

        // Remove trailing spaces
        while (!s.empty() && s.back() == ' ')
            s.pop_back();

        int i = 0;

        while (i < s.size()) {

            // Skip multiple spaces
            while (i < s.size() && s[i] == ' ')
                i++;

            string word = "";

            // Build one word
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            if (!word.empty())
                words.push_back(word);
        }

        // Reverse the words
        reverse(words.begin(), words.end());

        // Build answer
        string ans = "";

        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1)
                ans += " ";
        }

        return ans;
    }
};