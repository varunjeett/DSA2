#include<bits/stdc++.h>
using namespace std;

// Maximum AND Value generated by any pair of element from the array.
int find(int newvalue,int arr[],int n){
    int ctr=0;
    for(int i=0;i<n;i++){
        int ele=arr[i];
        if((ele&newvalue) == newvalue)
            ctr++;
    }
    
    return ctr;
}

int maxAND (int arr[], int n)
{
    // Your code here
    int res=0;
    int mask=(1<<30);
    
    //for each bit position, find if there exists tow numbers with 1 at the same postion + store the previous result
    //as it must be satisfiedd
    while(mask > 0){
        int newvalue=(res|mask);//previous stored bit plus find new bit
        
        int count=find(newvalue,arr,n);

        //new bit found, store it in the result
        if(count>=2)
            res=newvalue;
            
        mask=mask>>1;
    }
    
    return res;
}

// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

class tnode{
    public:
    int val=-1;
    int mn=INT_MAX;//to store the minimum value which travelled this node during insertion
    tnode* left=NULL;
    tnode* right=NULL;
    
    tnode(){
    }
    
    tnode(int val){
        this->val=val;
    }
};
class Solution {
public:
    
    void insert(tnode* root,int ele){
        tnode* curr=root;
        int mask=(1<<30);
        while(mask > 0){
            int value=(ele&mask);
            if(value > 0){//bit at that positiion in ele is 1, go right in the tree
                if(curr-> right==NULL){
                    tnode* newnode=new tnode(1);
                    newnode->mn=min(newnode->mn,ele);//update the minimum passed value of each node
                    curr->right=newnode;
                    curr=newnode;
                }
                else{
                    curr=curr->right;
                    curr->mn=min(curr->mn,ele);//update the minimum passed value of each node
                }
            }
            
            else{
                if(curr->left==NULL){
                    tnode* newnode=new tnode(0);
                    newnode->mn=min(newnode->mn,ele);//update the minimum passed value of each node
                    curr->left=newnode;
                    curr=newnode;
                }
                else{
                    curr=curr->left;
                    curr->mn=min(curr->mn,ele);//update the minimum passed value of each node
                }
            }
            
            mask=(mask>>1);
        }
    }
    
    int crawl(tnode* root,int ele,int limit){
        int mx=0;
        tnode* curr=root;
        int mask=(1<<30);
        for(int i=30;i>=0 && curr;i--)
        {
            int value=(ele&mask);
            if(value > 0){//bit at that positiion in ele is 1, we want 0 
               
                //traverse this path only if the minimum passsed value is less equal to limit given by query
                if(curr-> left && (limit >= (curr->left)->mn)){ //wanted 0, got 0, turnon the bit
                    int turnon=(1<<i);
                    mx=(mx|turnon);
                    curr=curr->left;
                }
                else{//wanted 0 ,got 1,keep that bit off
                    curr=curr->right;
                }
            }
            
            else{//bit at that positiion in ele is 0, we want 1 
                
                //traverse this path only if the minimum passsed value is less equal to limit given by query
                if(curr->right  && (limit >= (curr->right)->mn)){//wanted 1, got 1, turnon the bit
                    int turnon=(1<<i);
                    mx=(mx|turnon);
                    curr=curr->right;
                }
                else{//wanted 1 ,got 0,keep that bit off
                    curr=curr->left;
                }
            }
            
            mask=(mask>>1);
        }
        
        return mx;
    }
    
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int mn=INT_MAX;
        tnode* root=new tnode();
        
        for(int ele:nums){
            mn=min(mn,ele);
            insert(root,ele);
        }
        
        vector<int> ans;
        for(auto &x:queries){
            if(mn > x[1])//if the smallest element of the array is greater than the limit by query so not possible
                ans.push_back(-1);
            else
                ans.push_back(crawl(root,x[0],x[1]));
        }
        return ans;
    }
};


// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
//similiar to above questions
class tnode{
    public:
    int val=-1;
    tnode* left=NULL;
    tnode* right=NULL;
    
    tnode(){
    }
    
    tnode(int val){
        this->val=val;
    }
};

class Solution {
public:
    
    //height of trie
    int findHeight(int num){
        int h=0;
        while(num > 0){
            num=(num >> 1);
            h++;
        }
        return h;
    }
    
    void insert(tnode* root,int ele,int height){
        tnode* curr=root;
        int mask=(1<<height);
        while(mask > 0){
            int value=(ele&mask);
            if(value > 0){//bit at that positiion in ele is 1, go right in the tree
                if(curr-> right==NULL){
                    tnode* newnode=new tnode(1);
                    curr->right=newnode;
                    curr=newnode;
                }
                else{
                    curr=curr->right;
                }
            }
            
            else{
                if(curr->left==NULL){
                    tnode* newnode=new tnode(0);
                    curr->left=newnode;
                    curr=newnode;
                }
                else{
                    curr=curr->left;
                }
            }
            
            mask=(mask>>1);
        }
    }
    
    int crawl(tnode* root,int ele,int height){
        int mx=0;
        tnode* curr=root;
        int mask=(1<<height);
        for(int i=height;i>=0;i--)
        {
            int value=(ele&mask);
            if(value > 0){       //bit at that positiion in ele is 1, we want 0 
                if(curr-> left){ //wanted 0, got 0, turnon the bit
                    int turnon=(1<<i);
                    mx=(mx|turnon);
                    curr=curr->left;
                }
                else{//wanted 0 ,got 1,keep that bit off
                    curr=curr->right;
                }
            }
            
            else{//bit at that positiion in ele is 0, we want 1 
                if(curr->right){//wanted 1, got 1, turnon the bit
                    int turnon=(1<<i);
                    mx=(mx|turnon);
                    curr=curr->right;
                }
                else{//wanted 1 ,got 0,keep that bit off
                    curr=curr->left;
                }
            }
            
            mask=(mask>>1);
        }
        
        return mx;
    }
    
    
    
    
    int findMaximumXOR(vector<int>& nums) {
        int height=0;
        for(int ele:nums){
            height=max(height,findHeight(ele));
        }
        
        if(height==0)
            return 0;
        
        tnode* root=new tnode(-1);
        for(int ele:nums){
            insert(root,ele,height-1);
        }
        
        int ans=0;
        for(int ele:nums){
           ans=max(ans, crawl(root,ele,height-1));
        }
        
        return ans;
    }
};


// https://leetcode.com/problems/find-longest-awesome-substring/

class Solution {
public:
    //bit masking concept :  we need to make palindrome -> all characters even times OR one character odd times,rest even
    
    //whenever,odd even comes in the case , we can use bit masking
    
    //first case longest is even length palindrome
    // 12345..565656.
    //Just before starrting of 565656, the bit mask will be same as after ending of 565656, as 5 and 6 occur even times ,so the bits flipping will be cancel out
    
    //second case, twe have to look for masks with one bit difference.
    //loop through current mask , change one bit at a time and look for it in the hashmap
    
    int longestAwesome(string s) {
        unordered_map<int,int> mp;
        mp[0]=-1;//initial mask
        
        int ans=0;
        int cmask=0;
        for(int i=0;i<s.length();i++)
        {
            int num=s[i]-'0';
            
            cmask=(cmask^(1 << num));//toggle the bit
               
            //even length palindrome
            if(mp.find(cmask)!=mp.end())
                ans=max(ans,i-mp[cmask]);
            
            
            //toogle only one bit of current mask once at a time and find it in the map
            //as odd length palindrome has only one set bit
            //12345656 mask of this will be 0000011110
            //mask of 123 will be 0000001110
            //so as 45656 forms a palindrome 
            for(int d=0;d<=9;d++){
                int idx=(1<<d);
                int newmask=(cmask^idx);//toggle bit
                if(mp.find(newmask)!=mp.end())//find that in the map
                    ans=max(ans,i-mp[newmask]);
                
            }
            
            //as we wish to find the longest palindrome, store only the leftmost occurence of each mask, dont update the i for the mask which is earlier stored
            if(mp.find(cmask)==mp.end())
                mp[cmask]=i;
            
        }
    
        return ans;
    }
};