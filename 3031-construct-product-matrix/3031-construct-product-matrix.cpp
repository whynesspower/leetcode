class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        int MOD=12345;
        vector<vector<int>> ans(n, vector<int>(m, 1));
        // convert 2D matrix to 1D array
        vector<int>pre(n*m, 1), suf(n*m, 1);
        vector<int>nums;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums.push_back(g[i][j]);
            }
        }
        pre[0]=nums[0];
        int sz=nums.size();
        suf[sz-1]=nums[sz-1];
        // sz= n*m
        for(int i=1;i<sz;i++){
            pre[i]=(((pre[i-1])%MOD)*((nums[i])%MOD))%MOD;
        }
        for(int i=sz-2;i>=0;i--){
            suf[i]=(((suf[i+1])%MOD)*((nums[i])%MOD))%MOD;
        }
        int index=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // nums.push_back(g[i][j]);
                if((index)==0){
                    // if() 
                    ans[i][j]=((suf[index+1])%MOD)%MOD;
 
                }
                else if((index)==(sz-1)){
                    ans[i][j]=((pre[index-1])%MOD)%MOD;
                }
                else{
                    ans[i][j]=(((pre[index-1])%MOD) * ((suf[index+1])%MOD))%MOD;

                }
                index++;
            }
        }

        int x=pre.size();
        int y=suf.size();
        int z=nums.size();
        cout<<x<<" "<<y<<" "<<z<<endl;
        for(int i=0;i<x;i++){
            cout<<"Pre is "<<pre[i]<<" suff is "<<suf[i]<<" nums is "<< nums[i]<< " "<<endl;
            // pre[i]=(((pre[i-1])%MOD)*((nums[i])%MOD))%MOD;
        }

        return ans;
    }
};