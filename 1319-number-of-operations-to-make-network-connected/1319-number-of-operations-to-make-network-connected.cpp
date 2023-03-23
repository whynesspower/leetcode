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

    int makeConnected(int n, vector<vector<int>>& c) {
        parent.resize(n, -1);
        ranks.resize(n, 0);
        int cnt=0;
        for(int i=0;i<c.size();i++){
            int a= c[i][0];
            int b= c[i][1];
            int c= find(a);
            int d= find(b);
            if(c==d){
                cnt++;
            }
            else{
                uni(a,b);
            }
        }
        // unordered_set<int>st;
        int cntMinu1=0;
        for(int i=0;i<n;i++){
            // cout<<parent[i]<<" ";
            if(parent[i]==-1) cntMinu1++;
            // st.insert(parent[i]);
        }
        if(cnt>=(cntMinu1-1))return cntMinu1-1;
        else return -1;
    }
};