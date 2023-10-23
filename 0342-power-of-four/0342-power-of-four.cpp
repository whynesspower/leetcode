class Solution {
public:
    bool isPowerOfFour(int n) {
        // 100  :: 4
        // 1000 :: 8
        // 10000:: 16
        // 100000:: 32
        // 1000000:: 64
        // STEP1:  only one set bit 
        
        
        // STEP2: followed by even number of unset bit
        
        int m=n;
        // int mask=1;
        int cnt=0;
        for(int i=0;i<32;i++){
            int mask=(1<<i);
            cout<<mask<<" ";
            if((mask&n)!=0){
                cnt++;
            }
        }
        cout<<endl<<cnt<<endl;
        if(cnt>1 or cnt==0) return false;

        int posOfSet=0;
        int mask=1;
        int cntOfUnset=0;
        while((mask&n)==0){
            cntOfUnset++;
            mask=(mask<<1);
        }
        cout<<endl<<cntOfUnset<<endl;
        if(cntOfUnset%2==0) return true;
        return false;
    }
};