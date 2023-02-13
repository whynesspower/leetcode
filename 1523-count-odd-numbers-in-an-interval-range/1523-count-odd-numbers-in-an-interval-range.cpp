class Solution {
public:
    int countOdds(int low, int high) {
        int a, b;
        if(high%2) a=(high+1)/2;
        else a= high/2;
        // int a= high/2;
        if(low%2) b= (low+1)/2;
        else b=low/2;
        if(low%2) return a-b+1;
        return a-b;
    }
};