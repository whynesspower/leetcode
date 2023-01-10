class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<pair<int,int>>st;
        vector<bool>vis(as.size(), true);
        vector<int>ans;
        for(int i=0;i<as.size();i++){
            if(as[i]>0){
                st.push({as[i], i});
            }
            else{
                while(!st.empty()){
                    int curr=st.top().first;
                    int idx=st.top().second;
                    st.pop();
                    if(curr>abs(as[i])){
                        st.push({curr, idx});
                        vis[i]=false;
                        break;
                    }
                    else if(curr<abs(as[i])){
                        vis[idx]=false;
                        continue;
                    }
                    else{
                        vis[idx]=false;
                        vis[i]=false;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<vis.size();i++){
            if(vis[i]==true) ans.push_back(as[i]);
        }
        return ans;
    }
};