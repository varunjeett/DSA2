#include <bits/stdc++.h>
using namespace std;

void bellmanford(int v,vector<vector<int>>& edges)
{
    vector<int> dis(v,1e9);
    int flag=0;//no neagtive weight cycle
    for(int i=0;i<v;i++)//loop v times
    {
        for(int e=0;e<edges.size();e++) //loop on edges
        {
            int x=edges[e][0];
            int y=edges[e][1];
            int w=edges[e][2];
            
            if(dis[x] + w < dis[y])
            {
                dis[y]=dis[x]+w;
                if(i==v-1)   //vth iteration mein khin bhi update ho
                {
                    flag=1;
                }
            }
        }
    }
    
    cout<<flag<<endl;
}


int main() {
    
	int t;
	cin>>t;
	while(t-- > 0)
	{
	    int v,e;
	    cin>>v>>e;
	    vector<vector<int>>edges;
	    int x,y,w;
	    for(int i=0;i<e;i++)
	    {
	        cin>>x>>y>>w;
	        edges.push_back({x,y,w});
	    }
	    
	    bellmanford(v,edges);
	}
	
	return 0;
}