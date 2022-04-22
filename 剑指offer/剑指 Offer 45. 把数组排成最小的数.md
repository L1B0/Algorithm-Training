```
class Solution {
public:
    static bool myfunc(int a, int b){
        stringstream ss;
        string aa, bb;

        ss << a;
        ss << b;
        ss >> aa;
        ss.clear();
        
        ss << b;
        ss << a;
        ss >> bb;

        if(aa.compare(bb) < 0) return true;
        else return false;
    }
    string minNumber(vector<int>& nums) {
        stringstream ss;
        string result, t;
        sort(nums.begin(), nums.end(), myfunc);
        
        for(int i=0;i<nums.size();i++)
        {
            ss << nums[i];
            ss >> t;
            ss.clear();
            result += t;
        }
        return result;
    }
};
```

