/*

// its a top down approach, so we need to decrement the index

    int helper(string word1, string word2,int i, int j)
    {

        if(i == -1 )
        {
            return j+1;
        }
        if(j == -1)
        {
            return i+1;
        }
        if(word1[i] == word2[j])
        {
            i--;
            j--;
            return helper(word1,word2,i,j);
        }
        int insert = helper(word1,word2,i-1,j);
        int replace = helper(word1,word2,i-1,j-1);
        int addition = helper(word1,word2,i,j-1);
        return 1 + min(min(insert,replace),addition);
    }

    int minDistance(string word1, string word2) {
        return helper(word1,word2,word1.length()-1,word2.length()-1);
    }

class Solution {
public:

    // its a top down approach, so we need to decrement the index

    int helper(string word1, string word2,int i, int j, vector<vector<int>> &table)
    {

        cout<<"i = "<<i<<" j = "<<j <<endl;

        if(table[i][j] != -1)
        {
            cout<<"table[i][j]  "<<table[i][j]<<endl;
           return table[i][j];
        }

        if(i == 0 )
        {
            cout<<"table[i][j]  "<<j<<endl;
            return table[i][j] = j;
        }
        if(j == 0)
        {
            cout<<"table[i][j]  "<<i<<endl;
            return table[i][j] = i;
        }
        if(word1[i-1] == word2[j-1])
        {
            cout<<word1[i-1]<<"  "<<word1[i-1]<<endl;
            return table[i][j] = helper(word1,word2,i-1,j-1,table);
        }
        int insert = helper(word1,word2,i-1,j,table);
        int replace = helper(word1,word2,i-1,j-1,table);
        int addition = helper(word1,word2,i,j-1,table);
        return table[i][j] = 1 + min(min(insert,replace),addition);
    }

    int minDistance(string word1, string word2) {
        static vector<vector<int>> table(word1.length()+1,vector<int>(word2.length()+1, -1));
        return helper(word1,word2,word1.length(),word2.length(),table);
    }
};

*/