// Given a string which consists of only 0, 1 or 2s, count the number of substring which have equal number of 0s, 1s and 2s.
#include <bits/stdc++.h>

using namespace std;

int find(string &str)
{
    unordered_map<string, int> mp;
    mp["0#0"]++;
    // "(count of zero -count of 1 )#(count of 0 - count of 2)"

    int ans = 0;

    int one = 0, zero = 0, two = 0;
    for (char ch : str)
    {
        if (ch - '0' == 0)
        {
            zero++;
        }
        else if (ch - '1' == 0)
        {
            one++;
        }
        else
        {
            two++;
        }

        string find = to_string(zero - one) + "#" + to_string(zero - two);
        ans += mp[find];
        mp[find]++;
    }

    return ans;
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string str;
        cin >> str;
        cout << find(str) << endl;
    }
    return 0;
}
