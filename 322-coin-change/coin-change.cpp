class Solution {
public:
    int ans(int n,vector<int>& coins,int amount,vector<vector<int>>& dp){
        if(n==0){
            if(amount%coins[n]==0){
                return amount/coins[n];
            }
            return 1e9;
        }
        if(dp[n][amount]!=-1) return dp[n][amount];
        int notake=0+ans(n-1,coins,amount,dp);
        int take=INT_MAX;
        if(coins[n]<=amount){
            take=1+ans(n,coins,amount-coins[n],dp);
        }
        return dp[n][amount]=min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int anss= ans(n-1,coins,amount,dp);
        if(anss>=1e9) return -1;
        return anss;
    }
};