class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<string> answer(n, "");
        
        for (int i = 0; i < n; i++) {
            string s = arr[i];
            int L = s.length();
            string best = "";
            
            // chhoti length se shuru karo
            for (int len = 1; len <= L && best.empty(); len++) {
                // sliding window se is length ke saare substrings nikaalo
                vector<string> candidates;
                for (int start = 0; start + len <= L; start++) {
                    candidates.push_back(s.substr(start, len));
                }
                
                // lexicographically sort karo
                sort(candidates.begin(), candidates.end());
                
                // duplicates hata do (agar same substring baar-baar aaya)
                candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
                
                // har candidate ko check karo baaki strings ke against
                for (string &cand : candidates) {
                    bool foundElsewhere = false;
                    
                    for (int j = 0; j < n; j++) {
                        if (j == i) continue; // apni khud ki string skip karo
                        
                        if (arr[j].find(cand) != string::npos) {
                            foundElsewhere = true;
                            break;
                        }
                    }
                    
                    if (!foundElsewhere) {
                        best = cand; // ye substring kisi doosri string mein nahi hai
                        break;
                    }
                }
            }
            
            answer[i] = best;
        }
        
        return answer;
    }
};