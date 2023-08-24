class Solution {
public:
    // int i=-1, j;
    string fillString(int &i, int j, vector<string>&words, int maxWidth, int currCharCnt){
        string currStr="";
        int whiteSpaces= maxWidth-currCharCnt;
        
        int numBlanks= j-i;
        if(j==words.size()-1 || numBlanks==0){
            while(i<j){
                currStr+=words[i];
                currStr+=' ';
                i++;
                whiteSpaces--;
            }
            currStr+=words[i];
            i++;
            while(whiteSpaces--){
                currStr+=' ';
            }
        }
        else{
        

                int extraWhiteSpace=whiteSpaces%numBlanks;
                int regularWhiteSpace=whiteSpaces/numBlanks;
                string extraWhiteStr="";
                while(regularWhiteSpace){
                    extraWhiteStr+=' ';
                    regularWhiteSpace--;
                }
                while(i<=j){
                    currStr+=words[i];
                    if(i<j)currStr+=extraWhiteStr;
                    if(extraWhiteSpace){
                        currStr+=' ';
                        extraWhiteSpace--;
                    }
                    i++;
                }
            
        }
        // cout<<i<<" "<<j<<" "<<endl;
        currCharCnt=0;
        return currStr;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int  j=0,i=0;
        int n=words.size();
        int currCharCnt=0;
        int tempHit=0;
        while(j<n){
            
            // cout<<currCharCnt<<" BEFORE: Curr CHar Cnt"<<endl;
            currCharCnt+=words[j].length();
            if(currCharCnt+j-i>maxWidth){
                string currString=fillString(i, j-1, words, maxWidth, currCharCnt-words[j].length());
                ans.push_back(currString);
                currCharCnt=words[j].length();
            }
            if(j==n-1){
                string currString=fillString(i, j, words, maxWidth, currCharCnt);
                ans.push_back(currString);
            }
            j++;
        }
        cout<<tempHit<<" dfdfdsfd: Curr CHar Cnt"<<endl;
        
        return ans;
    }
};