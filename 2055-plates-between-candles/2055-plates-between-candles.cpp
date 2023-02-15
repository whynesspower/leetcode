class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        int n= s.size();
        vector<int>numStars(n,0);
        vector<int>indxCandles;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='|'){
                indxCandles.push_back(i);
                if(i!=0)numStars[i]=numStars[i-1];
            }
            else{
                if(i==0)numStars[i]=(s[i]=='*'?1:0);
                else{
                    numStars[i]=numStars[i-1]+(s[i]=='*'?1:0);
                }
            }
        }
        for(int i=0;i<q.size();i++){
            int a= q[i][0];
            int b= q[i][1];
            if(indxCandles.size()<=1){
                ans.push_back(0);
                continue;
            }
            auto it= lower_bound(indxCandles.begin(), indxCandles.end(), a);
            auto it2= upper_bound(indxCandles.begin(), indxCandles.end(), b);
            if(it==indxCandles.end() and it2==indxCandles.end()){
                ans.push_back(0);
                continue;
            }
            if(it2==indxCandles.begin()){
                ans.push_back(0);
                continue;
            }
            it2--;
            
            int c= indxCandles[it2- indxCandles.begin()];
            int d= indxCandles[it- indxCandles.begin()];
            if(it==indxCandles.end() or it2==indxCandles.end()){
                ans.push_back(0);
                continue;
            }
            if(c> b or d> b){
                ans.push_back(0);
                continue;    
            }
            // cout<<*it2<<" "<<*it<<endl;
            // int c= indxCandles[it2- indxCandles.begin()];
            // int d= indxCandles[it- indxCandles.begin()];
            // cout<<c<<" "<<d<<endl;
            ans.push_back(numStars[c]- numStars[d]);
        }
        
        return ans;
    }
};