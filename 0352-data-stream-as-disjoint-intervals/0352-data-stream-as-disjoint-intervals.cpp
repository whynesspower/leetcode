class SummaryRanges 
{
public:
    vector<int> arr;
    set<int> set_check;
    SummaryRanges() 
    {
        
    }
    
    void addNum(int value) 
    {
        //for stopping adding duplicate value
        //check value doesn't present in the stream 
        if(set_check.count(value)==0) 
        {
            arr.push_back(value);
            set_check.insert(value);
            sort(begin(arr), end(arr)); //sort array for getting intervals
        }
    }
    
    vector<vector<int>> getIntervals() 
    {
        vector<vector<int>> res;
        vector<int> temp; //storing interval
        int i, j;
        for(i=0; i<arr.size(); i++)
        {
            //initially take same start and end point for the interval
            temp.push_back(arr[i]);
            temp.push_back(arr[i]);
            for(j=i+1; j<arr.size(); j++) //for updating end point of the interval
            {
                if(arr[j]-1 == temp.back()) //if values are consecutive, we update end point
                    temp[1] = arr[j];
                else
                    break;
            }
            res.push_back(temp); //add the interval in the result
            temp.clear(); //clear the interval
            i=j-1; //updating index i

        }
        return res;
        
    }
};