//solve for manhatten distance == euclidean distance
//gives when x1==x2 or y1==y2 but not both at the same time
class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        // code here
        if(N==1)
            return 0;
        
        unordered_map<int,int>xmp;
        unordered_map<int,int>ymp;
        unordered_map<string,int>pmp;
        
        int ans=0;
        for(int i=0;i<N;i++){
            int x=X[i];
            int y=Y[i];
            string ss=to_string(x)+"#"+to_string(y);
            
            ans+=xmp[x];
            ans+=ymp[y];
            ans-=(pmp[ss]*2);
            
            xmp[x]++;
            ymp[y]++;
            pmp[ss]++;
        }
        
        return ans;
    }
};