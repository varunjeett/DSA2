// 307. Range Sum Query - Mutable
// https://leetcode.com/problems/range-sum-query-mutable/
class NumArray {
public:
    vector<int> tree;//to store the segment tree
    int len;//to hold the length of the given array
    
    NumArray(vector<int>& nums) {
        len=nums.size();
        tree=vector<int>(4*len+1,0);
        build(0,0,len-1,nums);
        return;
    }
    
    //created functions
    void build(int idx,int st,int ed,vector<int>& nums){
        if(st==ed)
        {
            tree[idx]=nums[st];
            return;
        }
           
        
        int mid=st+(ed-st)/2;
        build(2*idx+1,st,mid,nums);
        build(2*idx+2,mid+1,ed,nums);
        tree[idx]=tree[2*idx+1]+tree[2*idx+2];
        return ;
    }
    
    int query(int idx,int st,int ed,int qs,int qe){
        if(qs > qe){
            return 0;
        }
        
        if(st==qs && ed==qe)
            return tree[idx];
        
        int mid=st+(ed-st)/2;
        int l_qs=qs;
        int l_qe=min(qe,mid);
        
        int r_qs=max(mid+1,qs);
        int r_qe=qe;
        
        return query(2*idx+1,st,mid,l_qs,l_qe)+query(2*idx+2,mid+1,ed,r_qs,r_qe);
    }
    
    void point_update(int idx,int st,int ed,int qs,int qe,int val){
        if(qs > qe){
            return ;
        }
        
        if(st==qs && ed==qe)
        {
            tree[idx]=val;
            return;
        }
           
        
        int mid=st+(ed-st)/2;
        int l_qs=qs;
        int l_qe=min(qe,mid);
        
        int r_qs=max(mid+1,qs);
        int r_qe=qe;
        
        point_update(2*idx+1,st,mid,l_qs,l_qe,val);
        point_update(2*idx+2,mid+1,ed,r_qs,r_qe,val);
        tree[idx]=tree[2*idx+1]+tree[2*idx+2];
        return;
    }
    
    
    //given funtions
    void update(int index, int val) {
        point_update(0,0,len-1,index,index,val);
    }
    
    int sumRange(int left, int right) {
       return query(0,0,len-1,left,right);
    }
};