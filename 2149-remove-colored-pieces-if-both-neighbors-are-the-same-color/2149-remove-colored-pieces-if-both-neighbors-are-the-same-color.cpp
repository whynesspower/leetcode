class Solution {
public:
    bool winnerOfGame(string colors) {
        //ABAABBBBAAA
        int n=colors.size();
        int cntA=0, cntB=0;
        for(int i=0;i<n;i++){
            if(i<=1){
                continue;
            }
            if(colors.substr(i-2, 3)=="AAA"){
                cntA++;
            }
            if(colors.substr(i-2, 3)=="BBB"){
                cntB++;
            }
        }
        cout<<cntA<<" "<<cntB;
        return cntA>cntB;
    }
};