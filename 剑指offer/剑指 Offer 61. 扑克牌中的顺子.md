```
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int wang = 0, pre = -1, cha = 0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0) wang ++;
            else if(pre == -1) pre = nums[i];
            else{
                if(nums[i] == pre) return false;
                cha += nums[i] - pre - 1;
                pre = nums[i];   
            }
         }
        if(cha <= wang) return true;
        else return false;
    }
};
```

注意相同牌的情况