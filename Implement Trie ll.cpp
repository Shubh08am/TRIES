class Node{
    public:
        Node*links[26] ; 
        int cntEndWith=0; 
        int cntPrefix =0 ;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL; 
    }

    void put(char ch,Node*node){
        links[ch-'a'] = node; 
    }

    Node*get(char ch){
        return links[ch-'a'] ;
    }

    void increaseEnd(){
        cntEndWith++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    int getPrefix(){
        return cntPrefix ;
    }
    int getEnd(){
        return cntEndWith ;
    }
};
class Trie{

    public:
    Node*root; 
    Trie(){
        // Write your code here. 
        root = new Node() ; 
    }

    void insert(string &word){
        // Write your code here.
        Node*node = root ;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node()) ;
            }
            node=node->get(word[i]) ; 
            node -> increasePrefix() ;
        }
    node->increaseEnd();
    } 

    int countWordsEqualTo(string &word){
          Node*node = root ;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
               node=node->get(word[i]) ;
            }
            else return 0;
        }
    node->getEnd();
    }

    int countWordsStartingWith(string &word){
          Node*node = root ;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
               node=node->get(word[i]) ;
            }
            else return 0;
        }
    node->getPrefix();
    }

    void erase(string &word){
        Node*node = root ;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
               node=node->get(word[i]) ;
               node->reducePrefix();
            }
            else return;
        }
    node->deleteEnd();
    }
};
