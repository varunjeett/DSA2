#include <bits/stdc++.h>
using namespace std;

//given a window of size k,return the distinct elements in all windows of size k
vector<int> countDistinct(int a[], int n, int k)
{
    vector<int> ans;
    if (k > n)
    {
        return ans;
    }

    unordered_map<int, int> mp;

    //initial window of k
    for (int i = 0; i < k; i++)
    {
        mp[a[i]]++;
    }

    ans.push_back(mp.size());

    int ll = 0;
    int rr = k;

    //move the window one by one
    while (rr < n)
    {

        //acquire
        mp[a[rr]]++;

        //release
        if (--mp[a[ll]] == 0)
            mp.erase(a[ll]);

        ll++;

        //check and find
        ans.push_back(mp.size());

        //next iteration
        rr++;
    }
    return ans;
}

int find(vector<int> &arr)
{
    int ans = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        int mx = -1e9;
        int mn = 1e9;
        unordered_map<int, int> mp;
        for (int j = i; j < arr.size(); j++)
        {
            mx = max(mx, arr[j]);
            mn = min(mn, arr[j]);
            mp[arr[j]]++;

            if (mp.size() == j - i + 1 && j - i + 1 == mx - mn + 1)
                ans = max(ans, j - i + 1);

            if (j - i + 1 > mp.size())
                break;
        }
    }

    return ans;
}

//A subarray is equivalent if,count of unique integers in the subarray = count of unique integers in the given array.
int EquivalentSubarrays(vector<int> &arr)
{
    unordered_set<int> mp;
    for (int ele : arr)
    {
        mp.insert(ele);
    }

    int req = mp.size();
    int ll = 0;
    int rr = 0;
    int ans = 0;
    unordered_map<int, int> smp;
    while (rr < arr.size())
    {
        //acquire
        smp[arr[rr]]++;
        

        //as soon as we get required distinct character , calculate substrings and release on by one
        while (smp.size() == req)
        {
            ans += arr.size() - rr;//calculate
            if (--smp[arr[ll]] == 0)//release
                smp.erase(arr[ll]);

            ll++;
        }

        rr++;//next iteration
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }

    cout << find(arr) << endl;

    cout << EquivalentSubarrays(arr) << endl;
}