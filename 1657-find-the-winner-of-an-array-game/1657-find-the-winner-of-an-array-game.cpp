class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        // vector<int> t=arr;
        int maxi=INT_MIN;
        // sort(t.begin(), t.end());
        for(auto x: arr){
            maxi=max(maxi, x);
        }
        if(k==1){
            return max(arr[0], arr[1]);
        }
        // int currLen=0;
        int i=0;
        while(i<arr.size()){
            int j=i+1;
            while(j<arr.size()){
                if(arr[i]>arr[j]){
                    j++;
                    cout<<j<<" "<<i<<endl;
                    if(i==0){
                        if((j-i-1)>=k) return arr[i];
                    
                    }
                    else{

                        if((j-i)>=k) return arr[i];
                    }
                    continue;
                }
                else{
                    j++;
                    break;
                }
            }
            i=j-1;
            if(i>=arr.size()-1)break;
        }
        return maxi;
    }
};