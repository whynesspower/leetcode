class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        vector<int> secNum;
        while(k){
            secNum.push_back(k%10);
            k=k/10;
        }
        reverse(secNum.begin(), secNum.end());
        int i=num.size()-1, j=secNum.size()-1;
        int carry=0;
        int sum =0;
        while(i>=0 or j>=0){
            sum+=carry;
            if(i>=0) sum+= num[i--];
            if(j>=0) sum+= secNum[j--];
            ans.push_back(sum%10);
            carry= sum/10;
            sum=0;
        }
        if(carry)ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};