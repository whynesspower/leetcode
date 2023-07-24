class Solution {
public:
//     long long binpow(long long a, long long b, long long m)
//     {
      
//     }
    double myPow(double a, int n) {
        // a %= m;
        long long b=n;
        if(b<0){
            a=1/a;
            b=abs(b);
            cout<<b<<endl;
            
        }
        cout<<a<<" ";
        double res = 1;
        while (b > 0)
        {
            cout<<"temp"<<endl;
            if (b & 1)
                res = res * a;
                cout<<res<<" ";
            
            
                
            a = a * a ;
            b >>= 1;
            cout<<b<<" ";
        }
        return res;
    }
};