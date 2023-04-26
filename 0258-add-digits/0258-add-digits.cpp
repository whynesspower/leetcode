class Solution {
public:
    int addDigits(int num) {
        int original=num;
        int ans=original;
        // int ans;
        while(original>=10){
            ans=0;
            while(num){
                ans+=num%10;
                num=num/10;
            }

            original=ans;
            num=original;
            cout<<original<<endl;
            // final_ans=original;
        }
        return original;
    }
};