class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>time;
        for(int i=0;i<dist.size();i++){
            double t= (double)((double)dist[i]/(double)speed[i]);
            time.push_back(t);
            cout<<t<<" ";
        }
        sort(time.begin(), time.end());
        int i=0;
        int currT=0;
        int n=dist.size();
        while(i<n){
            if(time[i]<=currT) return i;
            i++;
            // if(time[i]-currT<=1) return i+1;
            currT++;
        }
      
        return dist.size();
    }
};