class Solution {
public:
    int dp[10001][101];
    int superEggDrop(int e, int f) {
        memset(dp, 0, sizeof(dp));
// Consider the problem in a different way:
// dp[m][x] means that, given x eggs and m moves,
// what is the maximum number of floors that can be checked

// The DP equation is: dp[m][x] = 1 + dp[m – 1][x – 1] + dp[m – 1][x],
// which means we take 1 move to a floor.
// If egg breaks, then we can check dp[m – 1][x – 1] floors.
// If egg doesn’t break, then we can check dp[m – 1][x] floors.

// Follow the below steps to solve the problem:

// Declare a 2-D array of size K+1 * N+1 and an integer m equal to zero
// While dp[m][n] < k
// increase ‘m’ by 1 and run a for loop from x equal to one till x is less than or equal to n
// Set dp[m][x] equal to 1 + dp[m-1][x-1] + dp[m-1][x]
// Return m
        int m =0;
        while(dp[m][e]<f){
            m++;
            for(int i=1;i<=e;i++){
                dp[m][i]=1+ dp[m-1][i-1]+ dp[m-1][i]; 
            }
        }
        return m;
    }
};