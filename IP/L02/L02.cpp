//01 matrix





//lc1162
class Solution {
public:
    vector<int> dir={-1,0,1,0,-1};
    int maxDistance(vector<vector<int>>& grid) {
        int R=grid.size();
        if(R==0)
            return 0;
        int C=grid[0].size();
        if(C==0)
            return 0;
        int zero=0;
        queue<pair<int,int>> q;
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i*C+j,0});
                }
                else 
                    zero++;
            }
        }
        
        if(zero==0)
            return -1;
        
        int mx=-1;
        while(q.size()!=0)
        {
            int sz=q.size();
            while(sz-- > 0)
            {
                pair<int,int> p=q.front();
                q.pop();
                
                int r=p.first/C;
                int c=p.first%C;
                mx=max(mx,p.second);
                
                for(int d=0;d<4;d++)
                {
                    int x=r+dir[d];
                    int y=c+dir[d+1];
                    
                    if(x>=0 && y>=0 && x<R && y<C && grid[x][y]==0)
                    {
                        grid[x][y]=1;
                        q.push({x*C+y,p.second+1});
                    } 
                }
            }
        }
        
        
        return mx;
    }
};



//lc332




//lc934
//convert one island into different numbers, grow the island by bfs till other 1 is found.
class Solution {
public:
    vector<int> dir={-1,0,1,0,-1};
    
    void dfs(int i,int j,vector<vector<int>>& A,queue<int> &q)
    {
        A[i][j]=2;
        q.push(i*A[0].size()+j);
        for(int d=0;d<dir.size()-1;d++)
        {
            int x=i+dir[d];
            int y=j+dir[d+1];
            if(x>=0 && y>=0 && x<A.size() && y<A[0].size() && A[x][y]==1)
            {
                dfs(x,y,A,q);
            }
        }
        return;
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        int r=A.size();
        if(r==0)
            return 0;
        int c=A[0].size();
        if(c==0)
            return 0;
        
        int flag=0;
        queue<int> q;
        for(int i=0;i<r && !flag;i++)
        {
            for(int j=0;j<c && !flag;j++)
            {
                if(A[i][j]==1)
                {
                    dfs(i,j,A,q);
                    flag=1;
                }
            }
        }
        
        
        int level=0;
        while(q.size()!=0)
        {
            int sz=q.size();
            while(sz-- > 0)
            {
                int rvtx=q.front();
                q.pop();
                
                int i=rvtx/c;
                int j=rvtx%c;
                
                for(int d=0;d<dir.size()-1;d++)
                {
                    int x=i+dir[d];
                    int y=j+dir[d+1];
                    
                    if(x>=0 && y>=0 && x<A.size() && y<A[0].size() && A[x][y]!=2)
                    {
                        if(A[x][y]==0)
                        {
                            A[x][y]=2;
                            q.push(x*c+y);
                        }
                        else if(A[x][y]==1)
                        {
                            return level;
                        }
                    }
                }
            }
            level++;
        }
    
        return level-1;
    }
    
};

//lc 1034

//can further optimise it.
class Solution {
public:
    vector<int> dir={-1,0,1,0,-1};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int r=grid.size();
        if(r==0)
            return grid;
        int c=grid[0].size();
        if(c==0)
            return grid;
        
        if(color==grid[r0][c0])
            return grid;
        
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        dfs(grid,r0,c0,color,grid[r0][c0],vis);
        
        return grid;
    }
    
    
    void dfs(vector<vector<int>>& grid, int r, int c, int color,int ocolor,vector<vector<bool>> &vis)
    {
        grid[r][c]=color;//marking true
        vis[r][c]=true;
        int count=0;
        for(int d=0;d<4;d++)
        {
            int x=r+dir[d];
            int y=c+dir[d+1];
            
            if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size())
            {
                if(grid[x][y]==ocolor)
                {
                    dfs(grid,x,y,color,ocolor,vis);
                    count++;
                }
               
                else if(vis[x][y])
                {
                count++;
                }
            }
            
        }
        
        if(count==4)//4 calls means, it was not on border, give back original color
        {
           grid[r][c]=ocolor; 
        }
        
        return;
    }
};















//finding the maximum flow algorithm , ford fulkerson
//bfs with back edge
//keep finding paths and for each path find the minimum portion, subtract and then create back edge
