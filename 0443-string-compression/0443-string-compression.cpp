class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size() , write = 0 , i = 0;
        while(i < n) {
            char c = chars[i];
            int j = i;
            while (j < n && chars[j]==c) {
                j++;
            }
            int cnt = j-i;
            chars[write++] = c;
            if (cnt > 1) {
                for(char d : std::to_string(cnt)){
                    chars[write++] = d;
                }
            }    
            i = j;
        }
        return write;
    }
};