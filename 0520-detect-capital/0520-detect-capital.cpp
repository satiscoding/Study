class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size() , up = 0;
        for(char c : word) {
            if(isupper((unsigned char)c)) up++;
        }
        return up==0 || up==n|| (up==1 && isupper((unsigned char)word[0]));
    }
};