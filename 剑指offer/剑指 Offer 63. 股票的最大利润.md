```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        
        int minBuy = prices[0], maxPro = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i] < minBuy)
                minBuy = prices[i];
            else{
                maxPro = maxPro > (prices[i]-minBuy) ? maxPro : (prices[i]-minBuy);
            }
        }
        return maxPro;
    }
};
```

