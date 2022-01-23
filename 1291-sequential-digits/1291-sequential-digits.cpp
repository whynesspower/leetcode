class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int l= to_string(low).size();
        int h=to_string(high).size();
        string str="123456789";
        vector<int>ans;
        for(int i=l; i<=h;i++){
            
            for(int j=0;j<=9-i;j++){
                
                int num= stoi(str.substr(j, i));
                if(num>=low and num<=high){
                    ans.push_back(num);
                }
            }
        }
        
        return ans;
        
    }
};