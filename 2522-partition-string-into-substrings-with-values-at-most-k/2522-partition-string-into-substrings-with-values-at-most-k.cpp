class Solution {
public:
    int minimumPartition(string s, int k) {


        long long  start_index = 0;
        vector<string> ss;
        for (long long  i = 0; i < s.length(); i++)
        {
            string sttr = s.substr(start_index, i - start_index + 1);
            if (stol(sttr) > k)
            {
                string temp=s.substr(start_index, i - start_index);
                if(temp.size()==0) return -1;
                if(stol(temp)>k) return -1;
                ss.push_back(temp);
                start_index = i;
            }
            if (i == s.length() - 1)
            {
                string tem=s.substr(start_index, i - start_index + 1);
                if(tem.size()==0) return -1;
                if(stol(tem)>k) return -1;
                ss.push_back(s.substr(start_index, i - start_index + 1));
            }
        }

         
        if(ss.size()==0) return -1;
        return ss.size();
        
    }
};