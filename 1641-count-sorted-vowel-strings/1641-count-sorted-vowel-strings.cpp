class Solution {
public:
    int countVowelStrings(int n) {
        int ans=0;
        for(int i=1;i<=(n+1);i++){
            int sum=0;
            for(int j=1;j<=i;j++){
                sum+=j;
                ans+=sum;
            }
        }
        return ans;
    }
};