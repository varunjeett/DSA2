#include <bits/stdc++.h>
using namespace std;

int find(vector<int> & arr, int k)
{
    unordered_map<int,int> mp;//running sum vs index
    int ans=0;
    mp[0]=-1;
    int csum=0;
    for(int i=0;i<arr.size();i++)
    {
        csum+=arr[i];
        int diff=csum-k;
        if(mp.find(diff)!=mp.end())
        {
            int idx=mp[diff];
            ans=max(ans,i-idx);
        }
        
        //keep the oldest(leftmost) value in the hashmap, so insert new csum values and dont update the already stored value
        if(mp.find(csum)==mp.end())
            mp[csum]=i;
    }
    
    return ans;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t-- > 0)
	{
	    int len,k;
	    cin>>len>>k;
	    vector<int> arr(len);
	    for(int i=0;i<len;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    cout<<find(arr,k)<<endl;
	}
	return 0;
}