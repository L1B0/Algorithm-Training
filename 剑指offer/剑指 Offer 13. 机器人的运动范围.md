```
class Solution {
public:
    int checknum[101][101],useFlag[101][101];
    void calcnum()
    {
        memset(checknum, 0, sizeof(checknum));
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
            {
                int t = 0, ii = i, jj = j;
                while(ii)
                {
                    t += (ii%10);
                    ii /= 10;
                }
                while(jj)
                {
                    t += (jj%10);
                    jj /= 10;
                }
                checknum[i][j] = t;
            }
        }
        return ;
    }

    int check(int i, int j, int m, int n)
    {
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;
        if(useFlag[i][j]) return 1;
        return 0;
    }

    int movingCount(int m, int n, int k) {
        int nums = 1;
        int dir[2][2] = { {-1, 0},  {0, -1} },
        starti = 1, startj = 1, ii, jj;

        memset(useFlag, 0, sizeof(useFlag));
        calcnum();

        useFlag[0][0] = 1;
        while(starti < m || startj < n)
        {
            if(startj < n)
            {
                for(int i=0;i<=starti-1;i++)
                {
                    if(checknum[i][startj] > k) continue;
                    for(int k=0;k<2;k++)
                    {
                        ii = i + dir[k][0], jj = startj + dir[k][1];
                        
                        if(check(ii,jj,m,n))
                        {
                            useFlag[i][startj] = 1;
                            nums ++;
                            break;
                        }
                    }
                }
            }
            
            if(starti < m)
            {
                for(int j=0;j<=startj-1;j++)
                {
                    if(checknum[starti][j] > k) continue;
                    for(int k=0;k<2;k++)
                    {
                        ii = starti + dir[k][0], jj = j + dir[k][1];
                        if(check(ii,jj,m,n))
                        {
                            useFlag[starti][j] = 1;
                            nums ++;
                            break;
                        }
                    }
                }
            }
            
            if(starti == m && startj < n && useFlag[starti-1][startj] == 0 && checknum[starti-1][startj] <= k)
            {
                if(check(starti-1,startj-1,m,n) || check(starti-2,startj,m,n))
                {
                    useFlag[starti-1][startj] = 1;
                    nums ++;
                }
            }
            else if(starti < m && startj == n && useFlag[starti][startj-1] == 0 && checknum[starti][startj-1] <= k)
            {
                if(check(starti-1,startj-1,m,n) || check(starti,startj-2,m,n))
                {
                    useFlag[starti][startj-1] = 1;
                    nums ++;
                }
            }
            else if(starti < m && startj < n && useFlag[starti][startj] == 0 && checknum[starti][startj] <= k)
            {
                if(check(starti-1,startj,m,n) || check(starti,startj-1,m,n))
                {
                    useFlag[starti][startj] = 1;
                    nums ++;
                }
            }

            if(starti < m)
                starti++;
            if(startj < n)
                startj++;
            
        }
        return nums;
    }
};
```

从0,0开始，一圈一圈遍历（1,1 2,2 3,3），每个点是否可达取决于其上面和左边的点是否可达。