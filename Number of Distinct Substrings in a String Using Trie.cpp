#include<bits/stdc++.h>
class Node{
public:
 Node*links[26] ; 
 bool containsKey(char ch) {return links[ch-'a'] !=NULL; }
 void put(char ch , Node*node) {links[ch-'a'] = node ; }
 Node*get(char ch) {return links[ch-'a'] ;}
};
int countDistinctSubstrings(string &s)
{
    int n = s.size() , cnt=0;
    Node*root = new Node()  ; 
    for(int i=0;i<n;i++){
        Node*node = root ; 
        for(int j=i;j<n;j++){
            if(!node->containsKey(s[j])){
                cnt++;
                node->put(s[j],new Node()) ; 
            }
              node=node->get(s[j]) ;
        }
    }
return cnt+1;
}
