//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
class Solution{
    public:
    int maxOccured(int L[], int R[], int n, int maxx){
        unordered_map<int,int>vec;
        // (range start/end) --> (currcnt) 
        int minx=INT_MAX;
        for(int i=0;i<n;i++){
            vec[L[i]]+=1;
            vec[R[i]+1]-=1;
            minx=min(minx, min(L[i], R[i]));
           
        }
        
        unordered_map<int,int>mp;
        int currcnt=0;
        int j=0;
       
        for(int i=minx;i<=maxx;i++){
            if(vec.find(i)!=vec.end())
                currcnt+=vec[i];
            mp[i]+=currcnt;
            
        }
        int ans=INT_MAX;
        int maxcnt=INT_MIN;
        for(auto &it:mp){
            // cout<<it.first<<" "<<it.second<<endl;
            if(it.second>=maxcnt){
                if(maxcnt==it.second){
                    ans=min(ans, it.first);
                }
                else{
                    maxcnt=it.second;
                    ans= it.first;
                }
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	int t;
	
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n;
	    
	    //taking size of array
	    cin >> n;
	    int L[n];
	    int R[n];
	    
	    //adding elements to array L
	    for(int i = 0;i<n;i++){
	        cin >> L[i];
	    }
	    
	    int maxx = 0;
	    
	    //adding elements to array R
	    for(int i = 0;i<n;i++){
	        
	        cin >> R[i];
	        if(R[i] > maxx){
	            maxx = R[i];
	        }
	    }
	    Solution ob;
	    
	    //calling maxOccured() function
	    cout << ob.maxOccured(L, R, n, maxx) << endl;
	}
	
	return 0;
}
// } Driver Code Ends