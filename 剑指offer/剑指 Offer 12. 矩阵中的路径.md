```
class Solution {
public:
    bool find(vector<vector<char>>& board, string word, int index, int i, int j, bool useFlag[201][201])
    {
        int len = word.length(), m = board.size(), n = board[0].size(), ii, jj;
        int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        bool flag = false;

        if(board[i][j] != word[index]) return false;
        if(index == len-1) return true; // find it!

        useFlag[i][j] = 1;
        for(int k =0;k<4;k++)
        {
            ii = i+dir[k][0], jj = j+dir[k][1];
            if( ii < 0 || ii >= m || jj < 0 || jj >= n ) continue;
            if(useFlag[ii][jj]) continue;
            
            flag |= find(board, word, index+1, ii, jj, useFlag);
            if(flag) return true; // make faster!
        }
        useFlag[i][j] = 0;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.length(), m = board.size(), n = board[0].size(), ii, jj;
        int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        bool flag = false, useFlag[201][201] = {0};

        if(len == 0) return false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] != word[0]) continue; 
                if(len == 1) return true; 
                
                // start point

                useFlag[i][j] = 1; // set use flag
                for(int k =0;k<4;k++)
                {
                    ii = i+dir[k][0], jj = j+dir[k][1];
                    if( ii < 0 || ii >= m || jj < 0 || jj >= n ) continue;

                    flag |= find(board, word, 1, ii, jj, useFlag);
                    if(flag) return true;// make faster!
                }
                useFlag[i][j] = 0; // clean use flag

                if(flag) return true;
            }
        }

        return false;
    }
};
```

