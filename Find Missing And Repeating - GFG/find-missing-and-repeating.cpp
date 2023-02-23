//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends


#define ll long long 
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *res = new int[2];
        // repesating ->  0
        // missing -> 1
        ll sum=0;
        
        for(ll i=0;i<n;i++ ){
            sum+=arr[i];
            arr[i]--;
        }
        ll sum2=n;
        sum2*=(n+1);
        sum2/=2;
        ll diff= sum2-sum;
        ll rep, miss;
        // int currxor=arr[0];
        // int prevxor=arr[0];
        for(ll i=0;i<n;i++ ){
            (arr[arr[i]%n]+=n);
        }
        for(ll i=0;i<n;i++){
            if(arr[i]>=n*2){
                // rep= arr[i]/n;
                rep=i+1;
                break;
            }
        }
        res[0]=rep;
        res[1]= rep+diff;
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends