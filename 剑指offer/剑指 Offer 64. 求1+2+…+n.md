```
class Solution {
public:
    int result;
    int sumNums(int n) {
        
        bool flag = n > 1 && sumNums(n-1) ;
        result += n;
        return result;
    }
};
```

