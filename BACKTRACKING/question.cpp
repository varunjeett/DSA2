// https://leetcode.com/problems/maximum-score-words-formed-by-letters/
// Given a list of words, list of  single letters (might be repeating) and score of every character.
// Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

class Solution {
public:
    int find(int pos, vector<string>& words, vector<int>& score,unordered_map<char,int>& mp)
    {
        if(pos==words.size())
            return 0;
        
        int ans=0;
        
        //not include
        ans=max(ans,find(pos+1,words,score,mp));
        
        
        //include
        int flag=1;
        int wordscore=0;
        for(char ch:words[pos])
        {
            mp[ch]--;
            if(mp[ch]<0)//not possible to create the word
                flag=0;
            wordscore+=score[ch-'a'];
        }
        
        //still possible to create word
        if(flag)
            ans=max(ans,wordscore+find(pos+1,words,score,mp));
        
        //restore the changes in the frequency array
        for(char ch:words[pos])
            mp[ch]++;

        return ans;   
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int len=words.size();
        if(len==0)
            return 0;
        
        //store the given letters
        unordered_map<char,int> mp;
        for(char ch:letters){
            mp[ch]++;
        }
        
        return find(0,words,score,mp);
    }
};