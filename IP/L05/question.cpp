#include <bits/stdc++.h>
using namespace std;

//longest substring with K unique character

//keep acquring till hashmap size remains equal to k
//keep releasing till the hashmap size is greater than k
int substringKunique(string &s, int k)
{
    if (s.length() < k)
    {
        return -1;
    }

    int ll = 0;
    int rr = 0;
    int ans = 0;
    unordered_map<char, int> mp;
    while (rr < s.length())
    {
        //acquire
        mp[s[rr]]++;

        //if hashmap size is greater than k , then release
        while (mp.size() > k)
        {
            if (--mp[s[ll]] == 0)
                mp.erase(s[ll]);
            ll++;
        }

        //check constraint
        if (mp.size() == k)
            ans = max(ans, rr - ll + 1);

        rr++; //for next iteration
    }

    return ans;
}

//k anagrams , if one string can convert to another within k conversions
bool areKAnagrams(string s1, string s2, int k)
{
    //add code here.
    if (s1.length() != s2.length())
        return false;

    unordered_map<char, int> mp;
    for (char ch : s2)
        mp[ch]++;

    int req = 0;
    for (char ch : s1)
    {
        if (mp[ch] == 0)
            req++;
        else
            mp[ch]--; //all non matching character to be converted ,so increment the required.
    }

    if (req <= k)
        return true;
    else
        return false;
}

//smallest substring with all occurences of the most frequent element
vector<int> smallestSubsegment(int a[], int n)
{
    // Complete the function
    vector<int> ans;
    unordered_map<int, vector<int>> mp;
    int mx = 0;
    for (int k = 0; k < n; k++)
    {
        int ele = a[k];
        // vector<int> & v=mp[ele];
        if (mp.find(ele) != mp.end())
        {                   //occured before
            mp[ele][1] = k; //store the new position
            mp[ele][2]++;   //increase the frequency
        }
        else
        { //first occurence
            mp[ele].push_back(k);
            mp[ele].push_back(k);
            mp[ele].push_back(1);
        }

        mx = max(mx, mp[ele][2]);
    }

    int len = INT16_MAX;
    int ll = 0;
    int rr = 0;

    for (auto &x : mp)
    {
        cout << x.first << " : ";
        cout << x.second[2] << endl;

        if (mx == x.second[2])
        {
            if (x.second[1] - x.second[0] + 1 < len)
            {
                len = x.second[1] - x.second[0] + 1;
                ll = x.second[0];
                rr = x.second[1];
            }
            else if (x.second[1] - x.second[0] + 1 == len)
            {
                if (x.second[0] < ll)
                {
                    ll = x.second[0];
                    rr = x.second[1];
                }
            }
        }
    }

    cout << ll << rr << endl;
    for (int k = ll; k <= rr; k++)
    {
        ans.push_back(a[k]);
        cout << a[k];
    }

    return ans;
}


// Let's analyze the problem.
// The problem provides us nums (an array of numbers) and a value p and wants us to find a subarry with the smallest length so that the sum of other elements can be divided by p.
// Assuming that the sum of nums is S, the sum of the target subarray is S1, and the sum of other elements in the nums is S2. Then, we haveS = S1 + S2.
// Now we know thatS2 % p == 0, we take modular p for equation S = S1 + S2, then we have S % p = S1 % p. As S is a known number i.e., sum(nums), we here use variable target to denote S % p.
// After that, the problem becomes finding a subarray with the smallest length and satisfying the equation S1 % p == target, whereS1 is the sum of a subarray.
// Let's define prefix_sum[i] = nums[0] + nums[1] + ... + nums[i-1], and S[i,j] = nums[i] + nums[i+1] + ... + nums[j-1], j > i
// Therefore, the sum of subarray S[i,j] = prefix_sum[j] - prefix_sum[i] , j > i.
// Take modular for the above equation, we get S[i,j] % p == (prefix_sum[j] - prefix_sum[i]) % p == target , j > i.
// Now, the problems becomes finding indexs i and j so that it satisfying the equation target == (prefix_sum[j] - prefix_sum[i]) % p , j > i.
// Then, we can rewrite the above equation as follows: (prefix_sum[j] - target) % p == prefix_sum[i] % p, j > i.
// 1590. Make Sum Divisible by P
class Solution {
public: 
    int minSubarray(vector<int>& nums, int p) {
        long long int csum=0;
        for(int ele:nums){
            csum+=ele;
        }
        
        int req=csum%p;
        cout<<req<<endl;
        if(req==0)
            return 0;
        
        //find the smallest subarray with remainder 4
        //(prefix_sum[j]-prefix_sum[i])%p==target
        // (prefix_sum[j] - target) % p (find in the hashmap) == prefix_sum[i] % p(store in hashmap),
        unordered_map<int,int> mp;
        mp[0]=-1;
        csum=0;
        int len=nums.size();
        for(int i=0;i<nums.size();i++){
            csum+=nums[i];
            if(mp.find((csum-req)%p)!=mp.end())
            {
                len=min(len,i-mp[(csum-req)%p]); 
            }
            mp[csum%p]=i;
        }
        return len==nums.size() ? -1 : len;
    }
};
