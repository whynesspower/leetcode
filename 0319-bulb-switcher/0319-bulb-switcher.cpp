class Solution {
public:
    int bulbSwitch(int n) {
        if(n<=1) return n;
        if(n==2) return 1;
        if(n==3) return 1;
        int a= sqrt(n);
        return a;
    }
};