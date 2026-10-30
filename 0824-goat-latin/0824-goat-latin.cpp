class Solution {
public:
    string toGoatLatin(string sentence) {
        stringstream ss(sentence);
        string w, res;
        int idx = 1;
        
        while (ss >> w) {
            char c_lower = tolower(static_cast<unsigned char>(w[0]));
            bool vowel = (c_lower == 'a' || c_lower == 'e' || c_lower == 'i' || c_lower == 'o' || c_lower == 'u');
            
            if (!vowel) {
                w = w.substr(1) + w[0];
            }
            
            w += "ma";
            w += string(idx, 'a');
            
            if (!res.empty()) {
                res += " ";
            }
            res += w;
            idx++;
        }
        return res;
    }
};