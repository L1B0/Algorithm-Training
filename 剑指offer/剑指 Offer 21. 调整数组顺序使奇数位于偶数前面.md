```
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> result;

        int len = nums.size(), l = 0, r = len-1;
        while(l < r){
            while(l < len && nums[l] % 2 != 0) l++;
            while(r >= 0 && nums[r] % 2 == 0) r--;
            if(l >= len || r < 0 || l >= r) break;

            int t = nums[l];
            nums[l] = nums[r];
            nums[r] = t;
            
            l++;
            r--;
        }

        return nums;
        /*
        int o = 0, j = 0, len =nums.size();
        while(j < len){
            if(nums[j] % 2)
                result.push_back(nums[j]);
            j ++;
        }

        while(o < len){
            if(nums[o] % 2 == 0)
                result.push_back(nums[o]);
            o ++;
        }
        */
        return result;
    }
};
```