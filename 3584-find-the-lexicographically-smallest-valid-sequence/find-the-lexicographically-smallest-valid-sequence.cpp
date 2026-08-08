#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> validSequence(std::string word1, std::string word2) {
        int n = word1.length();
        int m = word2.length();
        
        std::vector<int> last(m, -1);
        int p = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (p >= 0 && word1[p] != word2[j]) {
                p--;
            }
            if (p < 0) {
                break;
            }
            last[j] = p;
            p--;
        }
        
        std::vector<int> seq;
        seq.reserve(m);
        bool changed = false;
        int i = 0;
        
        for (int j = 0; j < m; ++j) {
            while (i < n) {
                bool is_match = (word1[i] == word2[j]);
        
                bool can_finish_exact = (j == m - 1) || (i < last[j + 1]);
                
                if (is_match) {
                    if (!changed || can_finish_exact) {
                        seq.push_back(i);
                        i++;
                        break;
                    }
                } else {
                    if (!changed && can_finish_exact) {
                        seq.push_back(i);
                        changed = true;
                        i++;
                        break;
                    }
                }
                
                i++;
            }
        }
        
        return (seq.size() == m) ? seq : std::vector<int>{};
    }
};