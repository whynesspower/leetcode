int  j=0,i=0;
int n=words.size();
int currCharCnt=0;
while(j<n){
cout<<currCharCnt<<" BEFORE: Curr CHar Cnt"<<endl;
currCharCnt+=words[j].length();
if(currCharCnt+j-i>maxWidth){
string currString=fillString(i, j-1, words, maxWidth, currCharCnt-words[j].length());
ans.push_back(currString);
currCharCnt=words[j].length();
if(currCharCnt>maxWidth){
string currString=fillString(i, j, words, maxWidth, currCharCnt);
ans.push_back(currString);
currCharCnt=0;
}
}
if(j==n-1){
string currString=fillString(i, j, words, maxWidth, currCharCnt);
ans.push_back(currString);
}
j++;
cout<<currCharCnt<<" AFTER: Curr CHar Cnt"<<endl;
}
return ans;
}
};
```