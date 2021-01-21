//count pairs divisible by k
int countkDivisibiles(int arr[], int n, int k)
{
    // Complete the function
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] % k;
    }

    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int r1 = arr[i];
        ans += mp[k - r1]; //r1+r2==4
        ans += mp[-r1];    //r1+r2==0

        mp[r1]++;
    }

    return ans;
}


//Given an array of integers arr of even length n and an integer k.
// We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
// Return True If you can find a way to do that or False otherwise.

class Solution
{
public:
    int countkDivisibiles(vector<int> &arr, int k)
    {
        // Complete the function
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = (arr[i] % k+k)%k;
            cout<<arr[i]<<" ";
        }

        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            int r1 = arr[i];
            if(mp.find(-r1) != mp.end() )
            {
                ans+=1;
                if(--mp[-r1]==0)
                    mp.erase(-r1);
                continue;
            }
            if (mp.find(k - r1) != mp.end())//(r1+r2==k) so r2=k-r1
            {
                ans += 1;
                if(--mp[k - r1]==0)
                    mp.erase(k-r1);
                continue;//remove that pair
            }
            mp[r1]++;
        }

        return ans;
    }
    bool canArrange(vector<int> &arr, int k)
    {
        return (2 * countkDivisibiles(arr, k) == arr.size()) ? true : false;
    }
};