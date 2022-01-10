class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;
        string ans="";
        int carry=0;
        while(i>=0 or j>=0){
            int temp1=0,temp2=0, temp3;

            if(i>=0){
                if(a[i]=='0')
                    temp1=0;
                else{
                    temp1=1;
                }
            }
            if(j>=0){
                if(b[j]=='0')
                    temp2=0;
                else{
                    temp2=1;
                }
            }
            temp3= (temp1+temp2 + carry)%2; 
            ans+=to_string(temp3);
            carry= (temp1+temp2+carry)/2;
            i--;
            j--;
        }
        
        while(carry){
            ans+=to_string(carry);
            carry--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};