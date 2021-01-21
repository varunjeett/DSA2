class Solution {
public:
    vector<vector<int>> dir={{-1,0},{-1,1},{-1,-1},{1,0},{1,1},{1,-1},{0,-1},{0,1},{0,0}};
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        long long int N=n;
        unordered_map<long long int,int> row;
        unordered_map<long long int,int> col;
        unordered_map<long long int,int> diag;
        unordered_map<long long int,int> adiag;
        unordered_map<long long int,int> lamp;
        
        for(const auto & ll:lamps){
            long long int x=ll[0];
            long long int y=ll[1];
            
            row[x]++;
            col[y]++;
            diag[x-y]++;
            adiag[x+y]++;
            lamp[x*N+y]++;
        }
        
        vector<int> ans;
        for(const auto & q:queries){
            long long int r=q[0];
            long long int c=q[1];
            
            int val=0;
            if(row[r]>0||col[c]>0||diag[r-c]>0||adiag[r+c]>0)
                val=1;
            
            ans.push_back(val);
            
            for(int d=0;d<dir.size();d++)
            {
                long long int x=r+dir[d][0];
                long long int y=c+dir[d][1];
                
                if(x>=0 && y>=0 && x<N && y<N && lamp[x*N+y]>0){
                    lamp[x*N+y]--;
                    row[x]--;
                    col[y]--;
                    diag[x-y]--;
                    adiag[x+y]--;
                }
                
            }
            
        }
        
        return ans;
    }
};