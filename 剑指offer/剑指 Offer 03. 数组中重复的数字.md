```c
int findRepeatNumber(int* nums, int numsSize){
    bool *flag;
    flag = malloc(sizeof(bool)*numsSize);
    memset(flag, false, sizeof(bool)*numsSize);

    for(int i=0;i<numsSize;i++)
    {
        if(flag[nums[i]])
        {
            free(flag);
            return nums[i];  
        }

        flag[nums[i]] = true;
    }
    return -1;
}
```

