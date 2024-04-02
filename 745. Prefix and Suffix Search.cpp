class Node{
public:
    unordered_map<char,Node*>links;
    //Node*links[26] won't work as '-' has ascii value of 45 so 45-97 will be <0 
    //so in order to use that use '{' as separator and links[27] as it has ascii value of 123 so 123-97 = 26 
    bool flag=false; 
    int index=-1; 
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void putKey(Node*node,char ch){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool getEnd(){
        return flag;
    }
    void setIndex(int ind){
        index=ind;
    }
    int getIndex(){
        return index;
    }
};
class Trie{
public:
    Node*root;
    Trie(){
        root=new Node();
    }
    void insert(string&words,int ind){
        int n=words.size();
        Node*node=root; 
        for(int i=0;i<n;i++){
            if(!node->containsKey(words[i])){
                node->putKey(new Node(),words[i]);
            }
            node=node->get(words[i]);
            node->setIndex(ind);
        }
    node->setEnd();
    }
    int startsWithPrefandEndWithSuff(string&words){
        int n=words.size();
        Node*node=root; 
        for(int i=0;i<n;i++){
            if(!node->containsKey(words[i])){
                return -1;
            }
            node=node->get(words[i]);
        }
    return node->getIndex();
    }
};
class WordFilter {
public:
    Trie t; 
    WordFilter(vector<string>& words) { 
        //In trie maintain index with every node 
        //insert -> suffix + separator + preffix 
        //do either --> insert all possible suffix and than whole prefix or reverse 
        //first we search for suffix and than go for prefix search 
        // apple -> 
        // e-apple 
        //le-apple 
        //ple-apple 
        //pple-apple 
        //apple-apple 
        
        int n=words.size(); 
        for(int i=0;i<n;i++){
            string w = words[i] ; 
            string s = "-"+w; 
            for(int j=w.size()-1;j>=0;j--){
                s=w[j]+s;
               // cout << s << " ";
                t.insert(s,i) ; 
            }
        }
    }
    
    int f(string pref, string suff) {
        string words = suff + '-' + pref ;
        return t.startsWithPrefandEndWithSuff(words);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
