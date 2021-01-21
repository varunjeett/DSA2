//no of subarray sum equals K
//hashmap approach :: sum(i,j)= PS[j]-PS[i-1]=target
//PS[j]-target=PS[i-1]   (key mathematics)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        int csum=0;
        int ans=0;
        for(int e:nums)
        {
            csum+=ele;
            int find=csum-k;//PS[j]-target=PS[i-1]
            ans+=mp[find];
            mp[csum]++;
        }
        
        return ans;
    }
};


//use the sliding window approach
// 11,6,3,6,1,9,5,5,0,0,10

int findSA(vector<int>& nums,int k)
{
    int ans=0;
    int csum=nums[0];
    int i=0;
    int j=0;
    while(j<nums.size())
    {
        if(csum==k)
        {
            ans++;
            cout<<i<<"from"<<j<<endl;
        }

        if(csum<=k)
        {
            j++;
            csum+=nums[j];
        }
        else
        {
            i++;
            csum=csum-nums[i-1];
        }

        if(i>j)
        {
            csum=nums[i];
            j=i;
        }

    }   
    while(i<nums.size())
    {
        i++;
        csum-=nums[i-1];
        if(csum==k)
        {
            ans++;
            cout<<i<<"from"<<j-1<<endl;
        }
    }

    return ans;

}

// 781. Rabbits in Forest
// In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell you how many other rabbits have the same color as them. Those answers are placed in an array.
// Return the minimum number of rabbits that could be in the forest.
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int ele:answers)
        {
            mp[ele]++;
        }
        
        int ans=0;
        
        for(auto i:mp){
            int grp=i.first+1;
            int fre=i.second;
            
            int noofgrp=ceil((fre*1.0)/grp);
            // 5 rabbits say unke jse 3 or hain, so minimum ke liye we'll assume that first 3 of 5 belong to the same group and rest 2 of 5 belong to the same group. so we have total 2 groups in minimum
            
            //not necessary ki har group ke member ko hum survey mein lee.
            ans+=noofgrp*grp;//no of groups *group size   
        }
        return ans;
        
    }
};


// Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.
//Logic:: PC0==PC1 
// =>PC0[j]-PC0[i-1]==PC1[j]-PC1[i-1] 
//  PC0[j]-PC1[j]==PC0[i-1]-PC1[i-1]
//  current running difference should be equal to previous stored difference (difference between count of zero and one)
long long int countSubarrWithEqualZeroAndOne(int arr[], int len)
{
    long long int ans=0;
    unordered_map<long long int,long long int> mp;
    mp[0]++;             //important point
    long long int one=0;
    long long int zero=0;
    
    for(int i=0;i<len;i++)
    {
        if(arr[i]==1)
            one++;
        else
            zero++;
        
        ans+=mp[one-zero];
        mp[one-zero]++;
    }    
    
    return ans;
}

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len=nums.size();
        unordered_map<int,int> map;
        int ans=0;
        int zero=0;
        int one=0;
        map[0]=-1;//(starting index-1)
        
        for(int j=0;j<nums.size();j++) {
            int ele=nums[j];
            if(ele==1)
                one++;
            else
                zero++;
            
            int diff=zero-one;
            int oldindex=map[diff];//PS[i-1]
            ans=max(ans,j-oldindex);
            map[diff]=min(oldindex,j);
        }
        return ans;
    }
};


// 713. Subarray Product Less Than K
// Your are given an array of positive integers nums.
// Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k<=1)
        return 0;
    long long int window=1;
    int left=0;
    int right=0;
    int ans=0;
    while(right < nums.size())
    {
        window*=nums[right];//acquire
        
        //release
        while(window >=k){//handle k=0,1 seperately as left will go out of bound
            window/=nums[left];
            left++;
        }
        
        
        //since if a window from left to right has product less than k, then all inside subarrays will have lesser product, so all possible subarray ending at right will be right-left+1
        ans+=right-left+1;//single element greater than k case is handled, as left=right+1, ans+=right-right-1+1 =0,no increment in answer, then right++ will take the loop forward.
        right++;
    }
    
    return ans;
}

//longest consecutive increasing subsequence
class Solution{
public:
    int sortingCost(int N, int arr[]){
        // code here
        int mx=0;
        unordered_map<int,int> mp;
        for(int i=0;i<N;i++){
            int ele=arr[i];
            if(mp.find(ele-1)!=mp.end()){
                mp[ele]=mp[ele-1]+1;
            }
            else
                mp[ele]=1;
                
            mx=max(mx,mp[ele]);
        }
        
        return N-mx;  
    }
};