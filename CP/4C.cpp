#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;
string find(string &s)
{
    if(mp.find(s)==mp.end())
    {
        mp[s]++;
        return "OK";
    }
    else
    {
        mp[s]++;
        string ans=s+to_string(mp[s]-1);
        return ans;
    }
}


int main()
{
    int n;
    cin>>n;
    while(n-- > 0)
    {
        string s;
        cin>>s;
        cout<<find(s)<<endl;
    }
}