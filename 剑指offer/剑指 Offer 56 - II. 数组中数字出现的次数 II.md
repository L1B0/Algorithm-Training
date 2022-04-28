```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[32] = {0}, m4x[32] = {0};
        for(int i=0;i<32;i++) m4x[i] = (1<<i);

        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<32;j++)
            {
                bits[j] += (nums[i]>>j)%2;
                if(nums[i] < m4x[j]) break;
            }
        }

        int result = 0;
        for(int i=0;i<32;i++)
        {
            if(bits[i]%3) result += (1<<i);
        }
        return result;
    }
};
```

相同的数字在每个二进制位上会出现3次。