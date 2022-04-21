```c
char* replaceSpace(char* s){
    char *newS, spcae[4] = "%20";
    newS = malloc(sizeof(char)*30000);

    int lenS = strlen(s), times = 0;
    for(int i=0;i<lenS;i++)
    {
        if(s[i] == ' ')
        {
            strcpy(&newS[i+times*2], spcae);
            times ++;
        }
        else newS[i+times*2] = s[i];
    }
    newS[lenS+times*2] = '\0';
    return newS;
}
```

