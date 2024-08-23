class Solution {
public:
Solution(){
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);
    }
     int maxProfit(vector<int>& prices) {
        int profit=0;int mx=-32768;
        for(int i=prices.size()-1;i>=0;i--){
            // if(mx < prices[i])
            // {
            //     mx=prices[i];
            // }
            mx=max(prices[i],mx);
            // if(mx-prices[i]>profit)
            // {
            //     profit=mx-prices[i];
            // }
            profit=max(profit,mx-prices[i]);
        }
        return profit;
    }
};