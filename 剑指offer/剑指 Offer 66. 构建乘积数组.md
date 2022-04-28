```
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.size() == 0) return NULL;
        vector<int> b;
        b.push_back(1);

        for(int i=1;i<a.size();i++)
        {
            b.push_back(b[i-1]*a[i-1]);
        }

        int temp = 1;
        for(int i=a.size()-2;i>=0;i--)
        {
            temp *= a[i+1];
            b[i] *= temp;
        }

        return b;
    } 
};
```

两次循环，从前到后，从后到前。