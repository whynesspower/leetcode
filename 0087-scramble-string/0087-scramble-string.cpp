class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() <= 1) return s1[0] == s2[0];
        if (mem.find(s1 + s2) != mem.end()) return mem[s1 + s2];
        
        // Pruning
        string t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) {
            mem[s1 + s2] = false;
            return false;
        }
        
        // 'i' splits the string s into two substrings [0, i) and [i, length)
        for (int i = 1; i < s1.size(); i++) {
            string x = s1.substr(0, i), y = s1.substr(i, s1.size() - i);
            if ((isScramble(s2.substr(0, x.size()), x) && isScramble(s2.substr(x.size(), y.size()), y)) ||
                (isScramble(s2.substr(0, y.size()), y) && isScramble(s2.substr(y.size(), x.size()), x))) {
                mem[s1 + s2] = true;
                return true;
            }
        }
        mem[s1 + s2] = false;
        return false;
    }
private:
    unordered_map<string, bool> mem;
};