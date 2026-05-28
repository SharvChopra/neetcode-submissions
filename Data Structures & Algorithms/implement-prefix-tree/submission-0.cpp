class PrefixTree {
public:
    struct trieNode{
        bool isendofword;
        trieNode *children[26];
    };

    trieNode *getNode(){
        trieNode *newNode = new trieNode();
        newNode->isendofword = false;
        for(int i=0;i<26;i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    trieNode *root;
    PrefixTree() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode *crawl = root;
        for(char ch:word){
            int idx = ch-'a';
            if(crawl->children[idx] == NULL){
                crawl->children[idx] = getNode();
            }
            crawl = crawl->children[idx];
        }
        crawl->isendofword = true;
    }
    
    bool search(string word) {
        trieNode *crawl = root;
        for(int i=0;i<word.length();i++){
            int idx = word[i]-'a';
            if(crawl->children[idx] == NULL){
                return false;
            }
            crawl = crawl->children[idx];
        }
        return (crawl!=NULL && crawl->isendofword);
    }
    
    bool startsWith(string prefix) {
        trieNode *crawl = root;
        int i = 0;
        for(i=0;i<prefix.length();i++){
            int idx = prefix[i]-'a';
            if(crawl->children[idx] == NULL){
                return false;
            }
            crawl = crawl->children[idx];
        }
        if(i==prefix.length()){
            return true;
        }
        return false;
    }
};
