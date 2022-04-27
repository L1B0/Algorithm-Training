```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0) return 0;
        return (n%2)+hammingWeight(n>>1);
    }
};
```

```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0) return 0;
        return 1+hammingWeight(n);
    }
};
```

