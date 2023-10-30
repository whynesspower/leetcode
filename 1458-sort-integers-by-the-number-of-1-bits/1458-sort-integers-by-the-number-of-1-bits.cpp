class Solution {
public:
    static bool cmp(int a, int b){
        int cnt1=0, cnt2=0;
        int mask1=1, mask2=1;
        for(int i=0;i<31;i++){
            mask1=1<<i;
            if(mask1&a){
                cnt1++;
            }
        }
        for(int i=0;i<31;i++){
            mask2=1<<i;
            if(mask2&b){
                cnt2++;
            }
        }
        if(cnt1==cnt2){
            return a<b;
        }
        else{
            if(cnt1<cnt2) return true;
            else return false;
        }
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};