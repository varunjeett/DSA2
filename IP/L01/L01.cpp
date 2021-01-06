#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;

    Job(int a, int b, int c)
    {
        this->id = a;
        this->dead = b;
        this->profit = c;
    }
};

//bellman ford
//to do
//ith iterattion mein i edge count wale path calculate hojaenge ??

void bellmanford()
{
    vector<vector<int>> edges = {{4, 3, -3}, {1, 4, 2}, {1, 3, 2}, {3, 1, 1}, {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {3, 2, 5}};
    int e = edges.size(); //no of edges
    int v = 5;            //no of nodes
    vector<int> dis(v, 1e9);
    int src = 0;
    dis[src] = 0;
    for (int i = 0; i < v - 1; i++) //(v-1) iterations
    {
        for (int e = 0; e < edges.size(); e++) //loop on edges
        {
            int u = edges[e][0];
            int v = edges[e][1];
            int cost = edges[e][2];

            if (dis[u] + cost < dis[v])
            {
                dis[v] = dis[u] + cost;
            }
        }
    }

    for (int i = 0; i < dis.size(); i++)
    {
        cout << "Distance of " << i << " from src: " << src << " is " << dis[i] << endl;
    }
}

//job sequencing problem
//sort by nlogn and then for each n, placing it in the deadline array by n*deadline therefore,worst case we have n*n.
//optimise it using dsu to n*log(deadline) ??
//questions and todo :: optimise using DSU??
void jobsequence()
{
    vector<vector<int>> job = {{1, 2, 70}, {2, 1, 190}, {3, 2, 3}, {4, 1, 25}, {5, 1, 15}};
    int n = 5;
    vector<Job> arr;
    for (int i = 0; i < job.size(); i++)
    {
        // Job j;
        // j.id=job[i][0];
        // j.dead=job[i][1];
        // j.profit=job[i][2];
        arr.push_back(Job(job[i][0], job[i][1], job[i][2]));
    }

    // for (Job js : arr)
    // {
    //     cout << js.id << " " << js.dead << " " << js.profit << endl;
    // }

    // sort(arr.begin(), arr.end(), [](Job &t, Job &o) {
    //     return t.profit < o.profit;//increasing order
    // });

    //step 1 : sort the array on profit
    sort(arr.begin(), arr.end(), [](Job &t, Job &o) {
        return t.profit > o.profit; //most profitable on top
    });

    //step 2 : make the answer array
    vector<int> ans(n + 1, -1); //n=5

    int totalprofit = 0;
    int numjob = 0;
    //step 3 : traverse on the job array
    for (Job js : arr)
    {
        // cout << js.id << " " << js.dead << " " << js.profit << endl;
        int pos = js.dead;
        while (pos > 0)
        {
            if (ans[pos] == -1)
            {
                ans[pos] = js.id;
                totalprofit += js.profit;
                numjob++;
                break;
            }
            else
            {
                pos--;
            }
        }
    }

    cout << "Total Profit is " << totalprofit << endl;
    cout << "Total Jobs is " << numjob << endl;
}

//k similiar strings
//O(s1.length()* s1.length())
//lc 854
void lc854()
{
    class Solution
    {
    public:
        int kSimilarity(string A, string B)
        {
            int len = A.length();
            int level = 0;
            queue<pair<string, int>> q;
            unordered_set<string> map;
            map.insert(A);
            q.push({A, -1}); //the number is to store the index till which A and B are equal as of now
            while (q.size() != 0)
            {
                int sz = q.size();
                while (sz-- > 0)
                {
                    pair<string, int> p = q.front();
                    q.pop();

                    string rvtx = p.first;
                    int pos = p.second;

                    if (rvtx == B)
                    {
                        return level;
                    }

                    int i = pos + 1, j = pos + 1;
                    while (j != len)
                    {
                        if (rvtx[i] != B[j])
                        {
                            for (int k = i + 1; k < len; k++)
                            {
                                if (rvtx[k] == B[j])
                                {
                                    string Acopy = rvtx;
                                    char ch = Acopy[k];
                                    Acopy[k] = Acopy[i];
                                    Acopy[i] = ch;

                                    if (map.find(Acopy) == map.end())
                                        q.push({Acopy, i});

                                    map.insert(Acopy);
                                }
                            }
                            break;
                        }
                        else
                        {
                            i++;
                            j++;
                        }
                    }
                }
                level++;
            }
            return level;
        }
    };
}

//lc 1203
//sort items by dependencies
void lc1203()
{
    class Solution
    {
    public:
        vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &before)
        {

            vector<vector<int>> gp(n + (2 * m), vector<int>());

            //construct edges for the groups, use hashing logic for grouping
            for (int i = 0; i < group.size(); i++)
            {
                if (group[i] != -1)
                {
                    int entry = n + (2 * group[i]);
                    int exit = n + (2 * group[i]) + 1;

                    //create edges from entry to ith node , from ith node to exit
                    gp[entry].push_back(i);
                    gp[i].push_back(exit);
                }
            }

            //construct edges according to before rules
            for (int i = 0; i < before.size(); i++)
            {
                for (int j = 0; j < before[i].size(); j++)
                {
                    int from = before[i][j];
                    int to = i;

                    if (group[from] == -1 && group[to] == -1) //nodes in the same group or individual groups
                    {
                        gp[from].push_back(to);
                    }
                    else if (group[from] == -1) //from node individual ha, to node grp mein hai use its entry point
                    {
                        gp[from].push_back((n + (2 * group[to])));
                    }

                    else if (group[to] == -1) //from node grp mein hai so use the exit point for that, to individual ha
                    {
                        gp[(n + (2 * group[from]) + 1)].push_back(to);
                    }

                    else //both from and to belong to different groups
                    {
                        if (group[from] != group[to])
                            gp[n + (2 * group[from]) + 1].push_back(n + (2 * group[to]));
                        else
                            gp[from].push_back(to);
                    }
                }
            }

            vector<int> indegree(n + (2 * m), 0);
            //apply topological sorting

            //create indegree vector
            for (int i = 0; i < gp.size(); i++)
            {
                for (int j = 0; j < gp[i].size(); j++)
                {
                    indegree[gp[i][j]]++;
                }
            }

            //push nodes with indegree zero
            vector<int> ans;
            stack<int> st;
            for (int i = 0; i < indegree.size(); i++)
            {
                if (indegree[i] == 0)
                {
                    st.push(i);
                }
            }

            //apply kahn algo
            while (st.size() != 0)
            {
                int sz = st.size();
                while (sz-- > 0)
                {
                    int rvtx = st.top();
                    st.pop();

                    if (rvtx < n)
                        ans.push_back(rvtx);

                    for (int i = 0; i < gp[rvtx].size(); i++)
                    {
                        int node = gp[rvtx][i];
                        indegree[node]--;
                        if (indegree[node] == 0)
                        {
                            st.push(node);
                        }
                    }
                }
            }

            if (ans.size() != n)
                return {};
            else
                return ans;
        }
    };
}

void solve()
{
    // bellmanford();
    // jobsequence();
    lc854();
    lc1203();
}

int main()
{
    solve();
}
