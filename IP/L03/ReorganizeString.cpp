#include<bits/stdc++.h>
using namespace std;

struct mycomp
{
    bool operator()(pair<char, int> &left, pair<char, int> &right)
    {
        return left.second < right.second;
    }
};
//no two adjacent are same
//So use a variable to store the removed character, add a different character from PQ and then put the removed back in PQ

string reorganizeString(string S)
{
    if (S.length() <= 1)
        return S;

    unordered_map<char, int> mp;
    for (char ch : S)
        mp[ch]++;

    priority_queue<pair<char, int>, vector<pair<char, int>>, mycomp> pq;
    for (const auto &x : mp)
    {
        pq.push({x.first, x.second});
    }

    string ans;
    pair<char, int> temp{'!', 0};
    while (pq.size() > 0)
    {
        auto rvtx = pq.top();
        pq.pop();

        ans += rvtx.first;

        if (temp.second != 0)
            pq.push(temp);

        temp = rvtx;
        temp.second--;
    }

    return (temp.second == 0) ? ans : "";
}

//no k consective are same
//for example abcabc, here for k=3, all the substrings contain different characters
string reorganizeStringK(string S, int k)
{
    if (S.length() <= 1)
        return S;

    unordered_map<char,int> mp;
    for(char ch:S)
        mp[ch]++;
    
    priority_queue<pair<char, int>, vector<pair<char, int>>, mycomp> pq;
    for (const auto &x : mp)
    {
        pq.push({x.first, x.second});
    }

    string ans;
    queue<pair<char,int>> q;
    while (pq.size() > 0)
    {
        auto rvtx = pq.top();
        pq.pop();

        ans += rvtx.first;

        rvtx.second--;

        if(rvtx.second!=0)
            q.push(rvtx);

        if(q.size()==k)
        {
            auto putback=q.front();
            q.pop();

            pq.push(putback);
        }
    }

    return q.size()==0 ? ans:"";
}

bool sameFreq(string ss)
{
    // code here 
    unordered_map<char,int>mp;
    for(char ch:ss)
        mp[ch]++;

    int f=-1;
    int ft=0;
    int st=0;
    int s=-1;

    for(auto& x:mp)
    {
        // cout<<x.first<<","<<x.second<<endl;
        int freq=x.second;

        if(freq==f){
            ft++;
            continue;
        }
        
        if(freq==s){
            st++;
            continue;
        }

        if(f==-1)
        {
            f=freq;
            ft=1;
            continue;
        }
        
        if(s==-1)
        {
            s=freq;
            st=1;
            continue;
        }
    
        return false;//if we get third frequency
    }

    //only one frequency exists
    if(f==-1 || s==-1)
        return true;
    

    if(ft==1){
        return (f-1==0 || f-1==s)? true:false;
    }else if(st==1){
        return (s-1==0 || s-1==f)? true:false;
    }
    else{
        return false;
    }
    
}

int main()
{
   cout<<sameFreq("aaaccddeeff");
}