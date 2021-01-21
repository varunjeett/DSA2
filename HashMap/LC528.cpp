// 528. Random Pick with Weight
// You are given an array of positive integers w where w[i] describes the weight of ith index (0-indexed).
// We need to call the function pickIndex() which randomly returns an integer in the range [0, w.length - 1]. pickIndex() should return the integer proportional to its weight in the w array. For example, for w = [1, 3], the probability of picking the index 0 is 1 / (1 + 3) = 0.25 (i.e 25%) while the probability of picking the index 1 is 3 / (1 + 3) = 0.75 (i.e 75%).
// More formally, the probability of picking index i is w[i] / sum(w).

//step 1: [3,14,1,7]
//P(0)=3/25
//P(1)=14/25 
//P(2)=1/25 
//P(3)=7/25 
//make a pie chart graph/prefix sum : [3,17,18,25]
//Generate numbers between 0 to 24(0 to sum-1), so total of 25 numbers
// 0 ,1, 2  -> select 3 (next bigger) so probability becomes 3/25
// 3 to 16  -> select 17(next bigger) so probability becomes 14/25
// 17 to 17 -> select 1(next bigger) so probability becomes 1/25
// 18 to 24 -> select 25(next bigger) so probability becomes 7/25


class Solution
{
public:
    vector<int> bkt;
    int last;
    Solution(vector<int> &w)
    {
        if (w.size() > 0)
        {
            bkt.push_back(w[0]);
            for (int i = 1; i < w.size(); i++)
                bkt.push_back(bkt[i - 1] + w[i]);
            
            last=bkt[bkt.size()-1];
        }
        
    }

    int nextbigger(int target) {
        int left=0;
        int right=bkt.size()-1;
        
        while(left < right)
        {
            int mid=left+(right-left)/2;
            if(target >= bkt[mid])
                left=mid+1;
            else
                right=mid;
        }   
        return left;
    }
        
    int pickIndex()
    {
        int num=(rand()%last);
        return nextbigger(num);
    }
};


