class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0;
        sort(people.begin(), people.end());
        int l=0, r=people.size()-1;
        while(l<=r){
            if(people[l]>limit){
                l++;
                ans++;
            }
            else if(people[r]>limit){
                r--;
                ans++;
            }
            else if(l!=r and people[l]+ people[r] >limit){
                ans++;
                // l++;
                r--;
            }
            else{
                l++;
                r--;
                ans++;
            }
        }
        return ans;
    }
};