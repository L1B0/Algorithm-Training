## 题面

Write a function that reverses a string. The input string is given as an array of characters `s`.

You must do this by modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm) with `O(1)` extra memory.

 

**Example 1:**

```
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

**Example 2:**

```
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```

 

**Constraints:**

- `1 <= s.length <= 105`
- `s[i]` is a [printable ascii character](https://en.wikipedia.org/wiki/ASCII#Printable_characters).

## 解题思路

交换字符。

```


void reverseString(char* s, int sSize){
    int len = sSize/2;
    for(int i=0;i<len;i++)
    {
        char t = s[i];
        s[i] = s[sSize-i-1];
        s[sSize-i-1] = t;
    }
    return ;
}
```

