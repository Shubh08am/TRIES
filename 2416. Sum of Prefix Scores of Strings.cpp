class Node{
public: 
    Node*links[26]; 
    bool flag=false; 
    int count=0; 

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void putKey(Node*node,char ch){
        links[ch-'a'] = node;
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
   Node*root; 
    Trie(){
        root=new Node();
    }
    void insert(string&words){
        Node*node=root; 
        int n=words.size(); 
        for(int i=0;i<n;i++){
            if(!node->containsKey(words[i])){
                node->putKey(new Node(),words[i]);
            }
            node=node->get(words[i]);
            node->count++; 
           //cout << words[i] << " " << node->count << "\n" ;
        }
    node->setEnd();
    }
    int startsWith(string&words){
        Node*node=root; 
        int n=words.size(),prefix=0; 
        for(int i=0;i<n;i++){
            if(!node->containsKey(words[i])){
                return prefix;
            }
            node=node->get(words[i]);
            prefix+=node->count;
            //cout << words[i]  << " " <<prefix<<" "<< node->count << "\n" ;
        }
    return prefix;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        for(auto&w:words) t.insert(w);
        
        vector<int>ans; 
        for(auto&w:words){
            int curr_count = t.startsWith(w) ; 
            ans.push_back(curr_count);
        }
        
     return ans;
    }
};
