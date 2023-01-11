//{ Driver Code Starts



#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution{
public:
    int gcdExtended(int a, int b, int *x, int *y)
    {
        // Base Case
        if (a == 0)
        {
            *x = 0;
            *y = 1;
            return b;
        }
     
        int x1, y1; // To store results of recursive call
        int gcd = gcdExtended(b%a, a, &x1, &y1);
     
        // Update x and y using results of
        // recursive call
        *x = y1 - (b/a) * x1;
        *y = x1;
     
        return gcd;
    }
    vector<int> gcd(int a, int b){
        // code here
        vector<int>ans;
        int x, y;
        int g= gcdExtended(a, b, &x, &y);
        ans.push_back(g);
        ans.push_back(x);ans.push_back(y);
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        Solution ob;
        vector<int> v = ob.gcd(a,b);
        if(v.size()!=3)
            return 0;
        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
    }
    return 0; 
}
// } Driver Code Ends