```c
void reverseWords(char* s, int l, int r)
{
    char temp;
    while(l < r)
    {
        temp = s[l];
        s[l++] = s[r];
        s[r--] = temp;
    }
    return ;
}

char* reverseLeftWords(char* s, int n){
    int sLen = strlen(s);
    reverseWords(s, 0, n-1);
    reverseWords(s, n, sLen-1);
    reverseWords(s, 0, sLen-1);
    return s;
}
```

