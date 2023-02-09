class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> count[26];
        // creating a 2D vector of 
        // char, set<strings>
        for (auto& s: ideas)
            // filling that 2D space 
            count[s[0] - 'a'].insert(s.substr(1));
        long long res = 0;
        
        
        for(int i = 0; i < 26; ++i)
            for(int j = i + 1; j < 26; ++j) {   
                // iterating through every character 
                long long c1 = 0L, c2 = 0L;
                for (auto& c: count[i])
                    // if strings of first character
                    // are not found in second character's set
                    // then those are the valid strings from first 
                    // characters' set of string 
                    
                    if (!count[j].count(c)) c1++;

                for (auto& c: count[j])
                    // we are repeating the same for 
                    // second vector of strings
                    if (!count[i].count(c)) c2++;
                // in the end multiply to calculate all the 
                // possible choice among these two
                res += c1 * c2;
            }
        
        // twice the result as its going to every pair there 
        //exist two answers 
        return res * 2;
    }
};