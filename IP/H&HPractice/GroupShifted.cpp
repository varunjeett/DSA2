#include <bits/stdc++.h>
using namespace std;

void group(vector<string>& arr)
{
    //all the group members of a particular string are shifted versions of each other
    
    //think of the group leader say, the gap between the characters of all the group members will be same as the group leader
    
    //create a hash of differences of all the strings and those with the same hash are put in the same group
    
    unordered_map<string,vector<string>> mp;
    for(string & ss:arr){
        if(ss.length()==1)
            mp["#"].push_back(ss);
        else
        {
            string hash="";
            for(int i=1;i<ss.length();i++)
            {
                int j=i-1;
                int diff=(ss[i]-ss[j]+26)%26;
                hash+=to_string(diff)+"#";
            }
            
            mp[hash].push_back(ss);
        }
    }
    
    
    for(auto & x: mp)
    {
        for(string & s:mp[x.first])
            cout<<s<<" ";
        
        cout<<endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string>arr ;
    for (int i = 0; i < n; i++)
    {
        string  ele;
        cin >> ele;
        arr.push_back(ele);
    }
    
    group(arr);
    
}