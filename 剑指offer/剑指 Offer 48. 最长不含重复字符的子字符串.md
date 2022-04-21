```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, tempLen = 0, index[256] = {0}, l = 0, r = 0;
        
        while(r < s.length()){
            if(index[s[r]] == 0 || index[s[r]] < l)
            {
                index[s[r]] = r+1;
            }
            else
            {
                maxLen = max(maxLen, (r-l));

                l = index[s[r]];
                index[s[r]] = r+1;
            }
            r++;
        }
        maxLen = max(maxLen, (r-l));
        return maxLen;
    }
};
```