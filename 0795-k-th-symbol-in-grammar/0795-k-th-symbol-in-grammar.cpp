class Solution {
public: 
    int dfs(int i, int n, int k, bool flag){
        if(n==1){
            if(flag){
                return 1; 
            }
            return 0;
        }
        // if(k<1) return 0;
        int sz=(1<<(n-1));
        int halfsz=(1<<(n-2));
        if(k>halfsz){
            int m=k%halfsz;
            cout<<n<<" "<<k<<" "<<sz<<endl;
            return dfs(i, n-1, k-halfsz, !flag);
        }
        else{
            cout<<n<<" "<<k<<" "<<sz<<endl;
            return dfs(i, n-1, k, flag);  
        }

    }

    int kthGrammar(int n, int k) {
        bool reciprocal=false;
        return dfs(0,n, k, reciprocal);
    }
};