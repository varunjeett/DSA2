// 166. Fraction to Recurring Decimal
// Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.

class Solution {
public:
    string fractionToDecimal(int n, int d) {
        
        long long int num=n;
        long long int den=d;
        
        if(num==0)
            return "0";
        
        //convert the numerator and denominator into negatives
        int flag=0;
        if(num<0){
            num=-num;
            flag++;
        }
        
        if(den<0){
            den=-den;
            flag++;
        }
        
        //if final ans is negative
        string ans="";
        if(flag==1)
            ans+="-";
        
        unordered_map<long long int,int> mp;
        long long int q=num/den;
        long long int r=num%den;
        if(r==0){
            ans+=to_string(q);
            return ans;
        }
        ans+=to_string(q)+".";
        long long int i=ans.length();
        
        while(r!=0){
            if(mp.find(r)!=mp.end()){
                break;
            }
            mp[r]=i;//positiion of remainder and index
            r=r*10;
            while(r<den){
                r=r*10;
                ans+=to_string(0);
                i++;
            }
            long long int qq=r/den;
            ans+=to_string(qq);
            i++;
            long long int rr=r%den;
            r=rr;
        }
        
        if(r==0)
            return ans;
        else
        {
            ans+=")";
            string anss;
            //put the starting bracket at the correct positiion
            for(int pos=0;pos<mp[r];pos++){
                anss+=ans[pos];
            }
            anss+="(";
            for(int pos=mp[r];pos<ans.length();pos++){
                anss+=ans[pos];
            }
            return anss;
            
        }
    }
};