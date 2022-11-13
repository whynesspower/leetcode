//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
	    // Code here
	    vector<pair<int,int>>temp;
	    for(int i=0;i<n;i++){
	        temp.push_back({nums[i], i});
	    }
	    sort(temp.begin(), temp.end());
        vector<bool>visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i] or temp[i].second==i ){
                continue;
            }
            int ccycle_size=0;
            int j=i;
            while(!visited[j]){
                ccycle_size++;
                visited[j]=true;
                j=temp[j].second;
            }
            
            if(ccycle_size>0) ans+=(ccycle_size-1);
        }
	    return ans;
	    
	}
	
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends