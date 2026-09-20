class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if ( s.length() != goal.length()) {
            return false;
        }

        if (s == goal) {
            vector<int> count(26,0);
            for (char c : s) {
                count[c - 'a']++;
                if (count[c - 'a'] > 1){
                    return true;
                }
            }
            return false;
        }
        vector<int> mismatch;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                mismatch.push_back(i);
            }
        }

        if (mismatch.size() != 2){
            return false;
        }
        
        int i = mismatch[0];
        int j = mismatch[1];

        return s[i] == goal[j] && s[j] == goal[i];
        
    }
};