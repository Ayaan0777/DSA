class Solution {
public:
    int profit(int index,int buy,vector<int>& prices,int n,vector<vector<int>>& dp){
        if(index==n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy){
            dp[index][buy]=max(-prices[index]+profit(index+1,0,prices,n,dp),0+profit(index+1,1,prices,n,dp));
        }
        else{
            dp[index][buy]=max(prices[index]+profit(index+1,1,prices,n,dp),0+profit(index+1,0,prices,n,dp));
        }
        return dp[index][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return profit(0,1,prices,n,dp);
    }
};