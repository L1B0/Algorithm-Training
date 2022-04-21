```c
char firstUniqChar(char* s){
    int ret = 0, start = 0, Len = strlen(s), index[256] = {-1};
    char temp[256] = {0};

    memset(index, -1, sizeof(int)*256);
    for(int i=0;i<Len;i++)
    {
        if(index[s[i]] == -1)
        {
            index[s[i]] = start;
            temp[start++] = s[i];
        }
            
        else
        {
            temp[index[s[i]]] = 0;
        }
    }
        
    for(int i=0;i<start;i++)
        if(temp[i])
            return temp[i];
    return ' ';
}
```

