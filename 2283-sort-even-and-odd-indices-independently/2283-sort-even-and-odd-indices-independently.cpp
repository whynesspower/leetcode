class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> ans;
        vector<int> evenElements(101);
        vector<int> oddElements(101);
        for(int i=0;i<nums.size();i++){
            if(i%2){
                oddElements[nums[i]]++;
            }
            else{
                evenElements[nums[i]]++;
            }
        }
        int even=0, odd=100;
        for(int i=0;i<nums.size();i++){
            if(i%2){
                while(oddElements[odd]==0){
                    odd--;
                }
                nums[i]=odd;
                oddElements[odd]--;
            }
            else{
                while(evenElements[even]==0){
                    even++;
                }
                nums[i]=even;
                evenElements[even]--;
            }
        }

        return nums;
    }
};