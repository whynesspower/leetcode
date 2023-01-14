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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        ll n=s1.size();
        parent.resize(26,-1);
        ranks.resize(26);
        ll temp2=26;
        for(ll i=0;i<26;i++){
            ranks[i]=temp2;
            temp2--;
        }
        for(ll i=0;i<n;i++){
            uni(s1[i]-'a', s2[i]-'a');
        }
        string ans="";
        for(auto x:baseStr){
            ll temp=find(x-'a');
            char temp2=temp+'a';
            ans+=temp2;
        }
        return ans;
    }
};