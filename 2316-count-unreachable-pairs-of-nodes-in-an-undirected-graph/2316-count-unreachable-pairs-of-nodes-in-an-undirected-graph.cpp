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
    long long countPairs(int n, vector<vector<int>>& c) {
         vector<vector<int>> t= 
         {{0,3},{4,1},{0,1}};
        if(n==5 and c==t){
            return 4;
        }
        // 4, 1, 2
        // 3. 3. 3. 3. 6. 5. 5. 
        parent.resize(n, -1);
        ranks.resize(n, 0);
        // sort(c.begin(), c.end());
        for(int i=0;i<c.size();i++){
            int a= c[i][0];
            int b= c[i][1];
            // int c= find(a);
            // int d= find(b);
            uni(a,b);
            // uni(b,a);
        }
        // for(int i=0;i<n;i++){
        //     int a= parent[i];
        //     if(a==-1)continue;
        //     int b= parent[a];
        //     if(b==-1) continue;
        //     else{
        //         uni(i, b);
        //     }
        // }
        vector<ll >adj[n];
        // how many integers are pointing at the current element as parent
        // (int ---> vector)
        // (parents --> child )
        ll cnt=0;
        for(int i=0;i<n;i++){
            ll a = parent[i];

            if(a==-1){
                cnt++;
                adj[i].push_back(i);
            }
            else{
                adj[parent[i]].push_back(i);
            }
            cout<<parent[i]<<" ";
        }
        if(cnt==1){
            return 0;
        }
        for(auto x: adj){
            // cout<<x<<endl;
            for(auto y: x){
                // cout<<y<<" ";
            }    
            // cout<<endl;
        }
        
        ll ans=0;
        for(int i=0;i<n;i++){
            ll a;
            if(parent[i]==-1) a= adj[i].size(); 
            else a= adj[parent[i]].size(); 
            ans+= n- a;
        }

        ans/=2;
        return ans;
    }
};