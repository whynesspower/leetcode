class Solution {
public:
    
    void temp(queue<string>&q, unordered_set<string>&st,string &word){
        
        st.erase(word);
        for(int i=0;i<word.size();i++){
            char x= word[i];
            for(char c='a'; c<='z'; c++){
                word[i]=c;
                if(st.find(word)!=st.end()){
                    q.push(word);
                    st.erase(word);
                }
            }
            word[i]=x;
        }
        
    }
    
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<string>q;
        temp(q, st, beginWord);
        int ans= 2;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string currword= q.front();
                q.pop();
                if(currword==endWord){
                    return ans;
                }
                temp(q,st,currword);
            }
            ans++;
        }
        return 0;
    }
};