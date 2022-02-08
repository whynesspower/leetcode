class Solution {
public:
    int addDigits(int num) {
        
        if(num/10==0) return num;
        int temp=0;
        
        while(num){
            temp+= num%10;
            num/=10;
            if(num==0) break;
        }
        
        return addDigits(temp);
    }
};




