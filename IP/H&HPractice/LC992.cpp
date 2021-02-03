class Solution {
public:
    
    int atmostK(vector<int>& arr,int k)
    {
        unordered_map<int,int> mp;
        int ll=0;
        int rr=0;
        int ans=0;
        while(rr < arr.size()){
            //acquire
            mp[arr[rr]]++;
            
            //remove till size becomes less than k
            while(mp.size()>k)
            {
                if(--mp[arr[ll]]==0)
                    mp.erase(arr[ll]);

                ll++;
            }
            
            //store the answer now as mp size will be less than k
            ans+=rr-ll+1;//for k=0, managed as ll=rr+1 in that case, ans=rr-(rr+1)+1=0
            
            //next iteration
            rr++;
        }

        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return atmostK(arr,k)-atmostK(arr,k-1);      
    }
};