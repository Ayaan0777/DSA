class Solution {
public:
    int f(int i,vector<int>& arr, int k,vector<vector<int>>& dp){
        if(i==arr.size()) return 0;
        int maxi=INT_MIN;
        int maxi_sum=INT_MIN;
        int len=0;
        if(dp[i][k]!=-1) return dp[i][k];
        for(int j=i;j<min(i+k,(int)arr.size());j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+f(j+1,arr,k,dp);
            maxi_sum=max(maxi_sum,sum);
        }
        return dp[i][k]=maxi_sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return f(0,arr,k,dp);
    }
};