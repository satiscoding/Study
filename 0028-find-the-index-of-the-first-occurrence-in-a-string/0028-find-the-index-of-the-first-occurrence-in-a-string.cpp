class Solution {
public:
    vector<int> buildLPS(string needle) {
        int m = needle.length();
        vector<int> lps(m, 0);
        
        int len = 0; // length of previous longest prefix-suffix
        int i = 1;
        
        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }
    
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        if (m == 0) return 0;
        if (m > n) return -1;
        
        vector<int> lps = buildLPS(needle);
        
        int i = 0; // pointer for haystack
        int j = 0; // pointer for needle
        
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                
                if (j == m) {
                    return i - j; // match mil gaya, starting index return karo
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1]; // smartly needle pointer ko peeche le jao
                } else {
                    i++; // haystack pointer aage badhao
                }
            }
        }
        
        return -1; // koi match nahi mila
    }
};