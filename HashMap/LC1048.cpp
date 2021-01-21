// 1048. Longest String Chain

// Given a list of words, each word consists of English lowercase letters.

// Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

// A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

// Return the longest possible length of a word chain with words chosen from the given list of words.

//Lis concept of Dynmaic Programming
//sort in increasing order of length
class Solution
{
public:
    bool check(string &l, string &s)
    {
        //to check whether to string can be made same after adding one character
        int i = 0, j = 0;
        int err = 0;
        while (j < s.length())
        {

            cout << i << j << endl;

            if (l[i] != s[j])
            {
                if (err == 0)
                {
                    i++;
                    err++;
                }
                else
                    return false;
            }
            else
            {
                i++;
                j++;
            }
        }

        return true;
    }

    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string &left, string &right) {
            return left.length() < right.length();
        });

        int mx = 1;
        vector<int> lis(words.size(), 1);

        for (int i = 1; i < words.size(); i++)
        {
            if (words[i].length() > 1) //predecessor exists only when word length is greater than 1
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    if (words[j].length() + 1 < words[i].length()) //not possible if length difference is more than 1
                        break;
                    else if (words[j].length() + 1 == words[i].length() && check(words[i], words[j]))
                    {
                        lis[i] = max(lis[i], lis[j] + 1);
                        mx = max(mx, lis[i]);
                    }
                }
            }
        }
        return mx;
    }
};
