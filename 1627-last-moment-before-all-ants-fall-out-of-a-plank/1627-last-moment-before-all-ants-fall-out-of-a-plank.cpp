class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        sort(left.rbegin(), left.rend());
        sort(right.begin(), right.end());
        int a=INT_MIN;
        if(left.size()) a=left[0];
        int b=INT_MIN;
        if(right.size()) b=right[0];
        if(b==INT_MIN) return a;
        return max(n-b,a);
    }
};