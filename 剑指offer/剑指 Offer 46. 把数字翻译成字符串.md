```
class Solution {
public:
    int translateNum(int num) {
        if(num < 10) return 1;
        else if(num < 26) return 2;
        else if(num < 100) return 1;
        else{
            if(num%100 < 10)
                return translateNum(num/10);
            else if(num%100 < 26)
                return translateNum(num/10)+translateNum(num/100);
            else
                return translateNum(num/10);
        }
    }
};
```