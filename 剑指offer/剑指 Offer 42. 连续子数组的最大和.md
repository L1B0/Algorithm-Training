```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dpStart(nums.size(),0), dpEnd(nums.size(),0);
        int n = nums.size();

        dpStart[0] = dpEnd[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            dpEnd[i] = nums[i]+max(0,dpEnd[i-1]);
            dpStart[i] = max(dpStart[i-1], dpEnd[i]);
        }

        return dpStart[n-1];
    }
};
```