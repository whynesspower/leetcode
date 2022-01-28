class WordDictionary {
public:
struct TrieNode{
TrieNode* child[26];
bool isend;
TrieNode(){
isend=false;
for(int i=0;i<26;i++){
child[i]=NULL;
}
}
};
TrieNode* root=new TrieNode();
void insert(string &s){
TrieNode* curr= root;
for(int i=0;i<s.length();i++){
int index= s[i]-'a';
if(curr->child[index]==NULL){
curr->child[index]= new TrieNode();
}
curr= curr->child[index];
}
curr->isend=true;
}