class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        int start_indx=0, end_indx=intervals.size()-1;
        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }
        int low=0, high=intervals.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(intervals[mid][0]<=newInterval[0]){
                // high=mid-1;
                start_indx=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        low=0, high=intervals.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(intervals[mid][1]>=newInterval[1]){
                end_indx=mid;
                // low=mid+1;
                high=mid-1;
            }
            else{
                // high=mid-1;
                low=mid+1;
            }
        }
        if(intervals[start_indx][1]<newInterval[0]){
            start_indx++;
        }
        if(intervals[end_indx][0]>newInterval[1]){
            end_indx--;
        }
        for(int i=0;i<start_indx;i++){
            ans.push_back(intervals[i]);
        }
            vector<int>temp;
            int a= newInterval[0];
            if(start_indx<n) a=min(intervals[start_indx][0],newInterval[0]); 
            temp.push_back(a);
            int b= newInterval[1];
            if(end_indx>=0) b= max(intervals[end_indx][1], newInterval[1]);
            temp.push_back(b);
            ans.push_back(temp);
        for(int i=end_indx+1;i<intervals.size();i++){
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};