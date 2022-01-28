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
    
    bool searchTrie(string &s, TrieNode * curr, int pos, int n){

        if(s[pos]=='.'){
            bool flag=false;
            TrieNode *temp=curr;
            
            /* 
            its really necesaary for us to create this temp and increaement in 
            temp=curr->child[i] in this manner as when you search a word say "b." and you have a word
            say "bat" then if you increament curr->curr->child[i] it will go and search of isend true in char t 
            and not give a false answer;

            */
            for(int i=0;i<26;i++){
                if(pos==n-1 and curr->child[i]){
                    temp= curr->child[i];
                    flag |= temp->isend;
                }
                else if(curr->child[i] and searchTrie(s, curr->child[i], pos+1, n)){
                    return true;
                }
            }
            return flag;
        }
            
        else if(curr->child[s[pos]-'a']){
            if(pos==n-1){
                curr=curr->child[s[pos]-'a'];
                return curr->isend;
            }
            return searchTrie(s,curr->child[s[pos]-'a'], pos+1, n);
        }
        
        return false;
    }
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        return insert(word);    
    }
    
    bool search(string word) {
        return searchTrie(word, root, 0 , word.size());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */