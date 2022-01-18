class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int size=flowerbed.size();
        vector<bool>isvalid(size, 0);
        if(size==1){
            if(flowerbed[0]==0 and n <=1){
                return true;
            }
            else if(flowerbed[0]==1 and n==0){
                return true;
            }
            else return false;
        }
        if(flowerbed[0]==1){
            isvalid[0]=true;
        }
        if(flowerbed[0]==0 and flowerbed[1]==0){
            isvalid[0]=true;
            count++;
        }
        
        for(int i=1;i<size-1;i++){
            
            if(flowerbed[i]==1){
                isvalid[i]=true;
            }
            
            if(flowerbed[i]==0 and !isvalid[i-1] and flowerbed[i+1]==0){
                count++;
                isvalid[i]=true;
            }    
        }
        
        if(flowerbed[size-1]==0 and !isvalid[size-2]){
            count++;
        }
        if(count>=n){
            return true;
        }
        else return false;
    }
};