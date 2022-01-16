class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

        int n=seats.size();
        int LrgstLengthOfCosequtiveZereos=0;
        int countOfCurrZereos=0;
        
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                countOfCurrZereos++;
                LrgstLengthOfCosequtiveZereos= max(LrgstLengthOfCosequtiveZereos, countOfCurrZereos);
            }
            else{
                countOfCurrZereos=0;
            }
        }
        
        int left=0;
        countOfCurrZereos=0;
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                countOfCurrZereos++;
                left=max(left, countOfCurrZereos);
            }
            else{
                break;
            }
        }
        
        int right =0;
        countOfCurrZereos=0;
        for(int i=n-1;i>=0;i--){
            if(seats[i]==0){
                countOfCurrZereos++;
                right=max(countOfCurrZereos, right);
            }
            else{
                break;
            }
        }
        
        int FinalAnswer=  (LrgstLengthOfCosequtiveZereos+1)/2;
        FinalAnswer= max(FinalAnswer, left);
        FinalAnswer= max(FinalAnswer, right);
        return FinalAnswer;
    }
    
};