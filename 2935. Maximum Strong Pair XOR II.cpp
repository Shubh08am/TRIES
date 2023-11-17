class Node{
    public:
        Node*links[2] ; 
        int cntEndWith=0; 
        int cntPrefix =0 ;

     bool containsKey(int bit){
        return links[bit] != NULL; 
    }
    void put(int bit,Node*node){
        links[bit] = node;
    }
    Node*get(int bit){
        return links[bit] ;
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
    void insert(int num){
    Node*node = root;
    for(int i=31;i>=0;i--){
        //checking whether bit is set 
        //right shift ensures either 1 or 0 return
        //whereas left shift doesn't ensures it , it may return >1 as well 
         int bit = (num>>i)&1 ;//always use right shift to check bit is set
        if(!node->containsKey(bit)){
            node->put(bit,new Node());
        }
        node=node->get(bit);
        node -> increasePrefix() ;
    }
    node->increaseEnd();
}

    void erase(int num){
        Node*node = root ;
        for(int i=31;i>=0;i--){
             int bit = (num>>i)&1 ;
            if(node->containsKey(bit)){
               node=node->get(bit) ;
               node->reducePrefix();
            }
            else return;
        }
    node->deleteEnd();
    }
    
    int findMax(int num){
 Node*node = root;
 int res = 0 ;
    for(int i=31;i>=0;i--){
        int bit = (num>>i)&1 ;
        //opposite bit so that xor is maximized
        if(node->containsKey(!bit) && node->get(!bit)->getPrefix()){
            res = res | (1<<i) ;
            node=node->get(!bit);
        }
        else{
            node=node->get(bit);
        }
    }
return res;
}
};
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxXor=0;
         Trie* obj = new Trie(); 
        int j=0,n=nums.size();
        for(int i=0;i<n;i++){
            while(j<n && nums[j]-nums[i]<=nums[i]){
                obj->insert(nums[j++]); 
            }
            maxXor=max(maxXor,obj->findMax(nums[i]));
            obj->erase(nums[i]);
        }
    return maxXor;
    }
};
