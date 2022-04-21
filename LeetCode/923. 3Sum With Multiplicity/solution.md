## 题面

Given an integer array `arr`, and an integer `target`, return the number of tuples `i, j, k` such that `i < j < k` and `arr[i] + arr[j] + arr[k] == target`.

As the answer can be very large, return it **modulo** `109 + 7`.

 

**Example 1:**

```
Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
```

**Example 2:**

```
Input: arr = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.
```

 

**Constraints:**

- `3 <= arr.length <= 3000`
- `0 <= arr[i] <= 100`
- `0 <= target <= 300`

## 解题思路

打两个表，分别记录每个数的次数和出现的数。

两次循环确定前两个数，第三个数要注意一些边界条件。

```c
long long c(int a, int b)
{
    long long ret = a, retm = b, bb = b;

    while (--b) ret = ret * --a;
    while (bb - 1) retm *= --bb;

    ret = ret / retm;
    return ret % 1000000007;
}

int threeSumMulti(int* arr, int arrSize, int target) {
    long long times[101] = { 0 }, value[101] = { 0 }, valueNum = 0, m = 1000000000 + 7;
    long long num = 0;

    for (int i = 0;i < arrSize;i++)
        times[arr[i]] ++;
    for (int i = 0;i < 101;i++)
    {
        if (times[i] > 0)
            value[valueNum++] = i;
    }

    for (int i = 0;i < valueNum;i++)
    {
        for (int j = i;j < valueNum;j++)
        {
            if (i == j && times[value[i]] == 1) continue;

            long long v3 = target - value[i] - value[j];
            if (v3 < 0 || v3 < value[j] || v3 > 100) continue;
            if (times[v3] == 0) continue;
            if (i == j && v3 == value[i] && times[v3] < 3) continue;

            if (v3 == value[i] && i == j)
            {
                num += c(times[v3], 3);
                num %= m;
            }
            else if (i == j)
            {
                num += times[v3] * c(times[value[i]], 2);
                num %= m;
            }
            else if (v3 == value[i])
            {
                num += times[value[j]] * c(times[v3], 2);
                num %= m;
            }
            else if (v3 == value[j])
            {
                num += times[value[i]] * c(times[v3], 2);
                num %= m;
            }
            else
            {
                num += times[value[i]] * times[value[j]] * times[v3];
                num %= m;
            }
        }
    }
    return (int)num;
}
```

动态规划

