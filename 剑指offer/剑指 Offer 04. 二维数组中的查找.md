```c
/*
 * 输入 **matrix 是长度为 matrixSize 的数组指针的数组，其中每个元素（也是一个数组）
 * 的长度组成 *matrixColSize 数组作为另一输入，*matrixColSize 数组的长度也为 matrixSize
 */
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
    if(matrixSize == 0 || *matrixColSize == 0) return false;

    int n = matrixSize, l, r, m;
    
    for(int i=0;i<n;i++)
    {
        if(target < matrix[i][0] || target > matrix[i][matrixColSize[i]-1]) continue;
        
        l = 0, r = matrixColSize[i]-1;

        while(l <= r)
        {
            m = (l+r)/2;
            if(matrix[i][m] == target) return true;
            else if(matrix[i][m] < target) l = m+1;
            else r = m-1;
        }
    }

    return false;
}
```

