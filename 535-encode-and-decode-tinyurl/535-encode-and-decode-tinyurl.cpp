#include<time.h>


class Solution {
    private: 
        unordered_map<string, string> mp;
        string ans="";
    public:
        // Encodes a URL to a shortened URL.
        string encode(string longUrl) {
            ans+=(char)(floor(rand()%100));
            while(mp.find(ans)!=mp.end()){
                ans+=(char)(floor(rand()%100));
            }
            mp[ans]=longUrl;
            return ans;
        }

        // Decodes a shortened URL to its original URL.
        string decode(string shortUrl) {
            return mp[shortUrl];
        }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));