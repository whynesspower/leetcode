class Solution {
public:
    int bestClosingTime(string c) {
        int n=c.size();
        vector<int>cntY(n+1, 0);
        vector<int>cntN(n+1, 0);

        for(int i=n-1;i>=0;i--){
            cntY[i]=cntY[i+1]+( c[i]=='Y'?1:0);

        }

        cntN[0]=(c[0]=='N'?1:0);
   
        for(int i=1;i<n;i++){
            cntN[i]=cntN[i-1]+(c[i]=='N'?1:0);
       
        }
        cntN[n]=cntN[n-1];
        int ans=INT_MAX;
        int ansIndex=0;
        for(int i=0;i<=n;i++){
            if(i==0){
                if(ans>cntY[0]){
                    ans=min(ans, cntY[0]);
                    ansIndex=i;    
                }
                
            }
            else{
                if(ans>cntY[i]+cntN[i-1]){
                    ans=min(ans,cntY[i]+cntN[i-1]);
                    ansIndex=i;    
                }
            }
            
        }
        return ansIndex;
    }
};