```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int l = 0, len = nums.size(), r = len-1;

        while(l < r){
            int t = nums[l]+nums[r];
            if(t > target) r --;
            else if(t < target) l++;
            else{
                result.push_back(nums[l]);
                result.push_back(nums[r]);
                break;
            }
        }
        /*
        vector<bool> flag(1000001, false);
        int len = nums.size();

        for(int i=0;i<len;i++) flag[nums[i]] = 1;
        for(int i=0;i<len;i++){
            int t = target-nums[i];
            if(t < 0 || t > 1e6) continue;

            else if(flag[t] == true){
                result.push_back(nums[i]);
                result.push_back(t);
                break;
            }
        }
        */
        return result;
    }
};
```