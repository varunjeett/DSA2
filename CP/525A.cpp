#include<bits/stdc++.h>

using namespace std;

int findkeys(int n,string& s)
{
    int ans=0;
    unordered_map<char,int> mp;
    for(int i=0;i<s.length();i++)
    {
        if(i%2==0) //key
            mp[s[i]]++;
        else
        {
            char key=(char)('a'+(s[i]-'A'));
            if(mp.find(key)!=mp.end())
            {
                if(--mp[key]==0)
                    mp.erase(key);
            }
            else
                ans++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    cout<<findkeys(n,s)<<endl;   
}