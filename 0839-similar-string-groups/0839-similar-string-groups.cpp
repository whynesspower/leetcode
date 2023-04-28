#define ll long long
class Solution {
public:
    vector<ll> parent;
    vector<ll> ranks;
    
    ll find(ll x)
    {
        if (parent[x] == -1)
        {
            return x;
        }
        return find(parent[x]);
    }
    
    void uni(ll x, ll y)
    {
        ll xpar = find(x);
        ll ypar = find(y);
        if (xpar == ypar)
        {
            return;
        }
        if (ranks[xpar] < ranks[ypar])
        {
            parent[xpar] = ypar;
        }
        if (ranks[xpar] > ranks[ypar])
        {
            parent[ypar] = xpar;
        }
        if (ranks[xpar] == ranks[ypar])
        {
            ranks[ypar]++;
            parent[xpar] = ypar;
        }
    }
    
    bool IfSimilar(string &a, string &b){
        if(a==b) return true;
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])cnt++;
        }
        if(cnt!=2) return false;
        return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n= strs.size();
        parent.resize(n , -1);
        // unordered_map<int,int>mp;
        ranks.resize(n, 0);
        // for(int i=0;i<n;i++){
        //     mp[strs[i]]=i;
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(IfSimilar(strs[i], strs[j])){
                        uni(i,j);
                    }
                }
            }
        }
        // unordered_set<int>st;
        int ans=0;
        
        for(int i=0;i<n;i++){
            int x=parent[i];
            if(x==-1) ans++;
            // cout<<x<<" ";
            // if(st.find(x)==st.end()){
            //     if(x!=-1){
            //         st.insert(x);
            //     }
            //     ans++;
            // }
            // else{
            //     continue;
            // }
        }

        return ans;
    }
};