```
class Solution {
public:
    int fib(int n) {
        int result[101] = {0,1}, m4x = (int)(1e9+7);
        for(int i=2;i<=n;i++)
            result[i] = (result[i-1]+result[i-2])%m4x;
        return result[n];
    }
};
```