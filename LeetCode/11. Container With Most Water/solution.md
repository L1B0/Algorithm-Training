## 题面

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `ith` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return *the maximum amount of water a container can store*.

**Notice** that you may not slant the container.

 

**Example 1:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```

**Example 2:**

```
Input: height = [1,1]
Output: 1
```

 

**Constraints:**

- `n == height.length`
- `2 <= n <= 105`
- `0 <= height[i] <= 104`

## 解题思路

贪心，得到最大面积。

```c
int m1n(int a, int b)
{
    return a > b ? b : a; 
}
int m4x(int a, int b)
{
    return a > b ? a : b; 
}
int maxArea(int* height, int heightSize){
    int l = 0, r = heightSize-1, area = -1;
    
    while(l < r)
    {
        area = m4x(area, m1n(height[l], height[r])*(r-l));
        if(height[l] < height[r])
        {
            l ++;
        }
        else
        {
            r --;
        }
    }
    return area;
}
```

