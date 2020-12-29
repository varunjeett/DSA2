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

//lc 1203
//sort items by dependencies

void lc854()
{
}

void lc1203()
{
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
