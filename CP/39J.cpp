#include<bits/stdc++.h>
using namespace std;

void find(string& s1,string& s2)
{
    int err=0;
    int i=0,j=0;
    int pos=s1.length()-1;//if all characters match then the last character of the first string is to be removed
    for(int j=0;j<s2.length();j++)
    {
        if(s1[i]!=s2[j])
        {
            if(err==0)//first errror
            {
                pos=i++;
                err++;
                j--;
            }
            else//cannot bear second error
            {
                cout<<"0"<<endl;
                return;
            }   
        }
        else
        {
            i++;
        }
        
    }

    vector<int>ans;
    ans.push_back(pos+1);
    char ch=s1[pos];
    for(int x=pos+1;x<s1.length();x++)
    {
        if(s1[x]==ch)
        ans.push_back(x+1);
        else
        {
            break;
        }
        
    }

    for(int x=pos-1;x>=0;x--)
    {
        if(s1[x]==ch)
        ans.push_back(x+1);
        else
        {
            break;
        }
        
    }

    cout<<ans.size()<<endl;
    for(int ele:ans){
        cout<<ele<<" ";
    }


}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    find(s1,s2);
}