```
class Solution {
public:
    double myPow(double x, int n) {
        double result;
        
        if(n == 0) return (double)1;

        if(n == 1) return x;
        if(n == -1) return 1/x;

        result = myPow(x, n/2);
        result = result * result;
        if(n % 2 != 0)
        {
            if(n < 0) result = result*(1/x);
            else result = result*x;
        }
        
        return result;
    }
};
```

* n为负数
* 如何加速：二分