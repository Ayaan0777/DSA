class Solution {
public:
    int find(int ind,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(ind==0){
            return amount%coins[ind]==0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notake=find(ind-1,amount,coins,dp);
        int take=0;
        if(coins[ind]<=amount){
            take=find(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=take+notake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return find(n-1,amount,coins,dp);
    }
};