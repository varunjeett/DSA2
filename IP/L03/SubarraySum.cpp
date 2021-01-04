#include<bits/stdc++.h>
using namespace std;

//gives total number of Subarray with sum K with only positive numbers in O(1) space.
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
//similarly solve maximum size subarray sum equal K
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
            if(map.find(diff)==map.end())//phle exist nhi krta
            {
                map[diff]=j;
            }
            else//exist krta hai
            {
                ans=max(ans,j-map[diff]);
            }            
        }
        return ans;
    }


int main()
{
    vector<int> arr={9, 4, 20, 3, 10, 5};
    // cout<<findSA(arr,33);
    
    vector<int> nums={0,1,0,1,0,1,1,0,1,1,0};
    cout<<findMaxLength(nums);

}

