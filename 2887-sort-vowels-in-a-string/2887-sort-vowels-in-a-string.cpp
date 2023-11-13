class Solution {
public:
    string sortVowels(string s) {
        // capital vovels before small letter vovels
        string ans=s;
        set<char>st;
        // map<char, int>st2;
        vector<char>st2;
        vector<char>ch={'e', 'A','E', 'a', 'i', 'o', 'u', 'I', 'O', 'U'};
        for(auto x: ch){
            st.insert(x);
        }
        // for(auto x: st){
        //     cout<<x<<" ";
        // }
        vector<int>index;
        for(int i=0;i<s.size();i++){
            if(st.find(ans[i])==st.end()) continue;
            else{
                st2.push_back(ans[i]);
                // st2[ans[i]]++;
                index.push_back(i);
            } 
        }
        sort(st2.begin(), st2.end());
    
        
//         for(auto x: st2){
            
//             int i=*x
//             ans[index[i]]=st
//         }
        
        for(int i=0;i<index.size();i++){
            ans[index[i]]=st2[i];
        }
        return ans;
    }
};