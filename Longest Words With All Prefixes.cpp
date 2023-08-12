#include <bits/stdc++.h> 
class Node{
public:
Node*links[26] ; 
bool flag = false ; 

bool containsKey(char ch){
    return links[ch-'a'] != NULL ;
}

void put(char ch, Node*node){
    links[ch-'a'] = node ; 
}

Node*get(char ch){
    return links[ch-'a'] ;
}

void setEnd(){
    flag = true; 
}

bool isEnd(){
    return flag;
}
}; 

class Trie{
private: 
Node*root ; 
public:
Trie(){
    root = new Node()  ; 
}

void insert(string &word){
Node*node = root ; 
for(int i=0;i<word.size();i++){
    if(!node->containsKey(word[i])){
        node->put(word[i],new Node()) ; 
    }
    node=node->get(word[i]) ; 
}
node->setEnd();
}

bool checkPrefixExist(string&word){
    Node*node = root ; 
    for(int i=0;i<word.size();i++){
        if(node->containsKey(word[i])){
            node=node->get(word[i]) ; 
            if(node->isEnd()==false) return false;
        }
        else return false;
    }
return true ; 
}
};


string completeString(int n, vector<string> &a){
     Trie* obj = new Trie() ; 
     for(auto&word:a) obj->insert(word) ;  

     string res = "" ;
     for(auto&word:a){
         if(obj->checkPrefixExist(word)){
             if(word.size()>res.size()){
                 res=word;
             }
             else if(word.size()==res.size() && word<res){
                 res=word;
             }
         }
     }
     return res==""?"None":res ;

}
