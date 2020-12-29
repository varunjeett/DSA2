pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    //find the max deadline and create the answer array
    int D=-1e9;
    for(int i=0;i<n;i++)
    {
        D=max(D,arr[i].dead);
    }
    
    //create answer array
    vector<int> ans(D+1,-1);//n=5
    
    
    //sort the array by profit
    sort(arr, arr+n, [](Job &t, Job &o) {
        return t.profit > o.profit; //most profitable on top
    });

    int totalpro=0;
    int numjob=0;
    //placing of jobs in the deadline slots
    for (int i=0;i<n;i++)
    {
        Job js=arr[i];
        int pos=js.dead;
        while(pos > 0)
        {
            if(ans[pos]==-1)//place it closest to its actual deadline
            {
                ans[pos]=js.id;
                totalpro+=js.profit;
                numjob++;
                break;
            }
            else
            {
                pos--;
            }
            
        }
        
        if(numjob==n)//all the jobs get filled early exit
        {
            break;
        }
    }
    
    return {numjob,totalpro};
    
} 