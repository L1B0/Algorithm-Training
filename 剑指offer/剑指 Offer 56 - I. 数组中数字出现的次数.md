```
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> result;
        int temp=0;
        for(int i=0;i<nums.size();i++) temp ^= nums[i]; // find a^b
        
        int dif = 1;
        while((temp & dif) == 0) dif = dif*2; // find difference between a and b 

        int a = 0, b = 0;
        for(int i=0;i<nums.size();i++) // split nums to two parts
        {
            if(nums[i] & dif) a ^= nums[i]; 
            else b ^= nums[i];
        }

        result.push_back(a);
        result.push_back(b);
        return result;
    }
};
```

