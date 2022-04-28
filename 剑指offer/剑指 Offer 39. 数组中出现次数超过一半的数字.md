```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=0,x=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == x) n++;
            else
            {
                if(n == 0) x=nums[i];
                else n--;
            }
        }
        return x;
    }
};
```

