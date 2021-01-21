#include <bits/stdc++.h>
using namespace std;
 
void check(vector<vector<int>> &arr, int m, int n)
{
    unordered_set<int> row;
    unordered_set<int> col;
    int ones=0;
    //finding the blacklisted rows and columns
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                row.insert(i);
                col.insert(j);
            }
            else
            {
                ones++;
            }
            
        }
    }

    if(ones!=0 && (row.size()==m || col.size()==n))
    {
        cout << "NO" << endl;
        return;
    }
 
    //checking the ones against blacklisted rows and cols
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1 && row.find(i) != row.end() && col.find(j) != col.end())//if the row and col of 1 are both blacklisted, then its wrong
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
 
    cout << "YES" << endl;
    vector<vector<int>> ans(m, vector<int>(n, 1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row.find(i) != row.end() || col.find(j) != col.end())
                ans[i][j] = 0;
 
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
 
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    check(arr, m, n);
}