class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int storeIndex = 0;
        
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());
        
        // Step 2: Clean up spaces and reverse each word back
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                if (storeIndex != 0) {
                    s[storeIndex++] = ' ';
                }
                int start = storeIndex;
                while (i < n && s[i] != ' ') {
                    s[storeIndex++] = s[i++];
                }
                reverse(s.begin() + start, s.begin() + storeIndex);
            }
        }
        
        s.resize(storeIndex);
        return s;
    }
};