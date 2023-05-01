class Solution {
public:
    double average(vector<int>& salary) {
        // int n= salary.size();
        double sum=0;
        sort(salary.begin(), salary.end());
        int min_ele= *min_element(salary.begin(), salary.end());
        int max_ele= *max_element(salary.begin(), salary.end());
        int n=0;
        for(int i=0;i<salary.size();i++){
            if(salary[i]==min_ele or salary[i]==max_ele) continue;
            sum+=salary[i];
            n++;
        }
        double ans= (double)((double)sum/(double)n);
        return ans;
    }
};