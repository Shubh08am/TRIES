class Node{
public:
     vector<Node*>links{vector<Node *>(26, NULL)}; //equivalent to assigning only links = vector<Node*>(26,NULL)
     //Node*links[26]={NULL};
     bool flag=false; 
    
     bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void putKey(Node*node,char ch){
        links[ch-'a']=node;
    }
    Node*get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool getEnd(){
        return flag;
    }
};
class Trie{
public: 
    Node*root= new Node(); 
    
    void insert(string&word){
        Node*node=root; 
        int n=word.size(); 
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                node->putKey(new Node(),word[i]);
            }
            node=node->get(word[i]);
        }
    node->setEnd();
    }
    void dfs(Node*node,string &word,vector<string>&allPreffix){
        if(allPreffix.size()==3) return;
        //at a trie node word present if flag is true 
        if(node->getEnd()==true){
            allPreffix.push_back(word);
        }
        //go ahead from this node to search further preffixes 
        for(char ch='a';ch<='z';ch++){
            if(node->containsKey(ch)){
                word+=ch;
                dfs(node->get(ch),word,allPreffix);
                word.pop_back();
            }
        }
    }
    vector<string> startsWith(string&word){
        Node*node=root;
        vector<string>allPreffix;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                return allPreffix;
            }
            node=node->get(word[i]);
        }
        dfs(node,word,allPreffix);
    return allPreffix;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //TRIE + DFS 
        Trie t; 
        for(auto&word:products){
            t.insert(word);
        }
        string s; 
        vector<vector<string>>result;
        for(auto&ch:searchWord){
            s+=ch;
            vector<string>curr = t.startsWith(s);
            result.push_back(curr);
        }
    return result;
    }
};
