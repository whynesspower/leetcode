class Solution {
public:
    int cntbits(int a){
        int cnt=0;
        while(a){
            a=a&a-1;
            cnt++;
        }
        return cnt;
    }
    
    int maxProduct(vector<string>& words) {
        vector<pair<int,int>>temp;
        for(int i=0;i<words.size();i++){
            int a=0;
            for(int j=0;j<words[i].size();j++){
                int b = 1<<(words[i][j]-'a');
                a = a|b;
            }
            temp.push_back({a,i});
        }
        cout<<temp.size();
        int ans=0;
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp.size();j++){
                if(j==i)continue;
                if(temp[i].first &temp[j].first)continue;
                else{
                    int a = words[temp[i].second].size();
                    int b = words[temp[j].second].size();
                    int c = a*b;
                    ans=max(ans, c);
                }
            }
        }
        return ans;
    }
};