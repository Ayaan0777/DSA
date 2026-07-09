class Solution {
public:
    bool split(vector<int>& nums,int target,int i,vector<vector<int>> &dp){
        if(target==0)return true;
        if(i==0)return nums[0]==target;
        bool nontake=split(nums,target,i-1,dp);
        bool take=false;
        if(dp[i][target]!=-1) return dp[i][target];
        if(nums[i]<=target){
            take=split(nums,target-nums[i],i-1,dp);
        }
        return dp[i][target]=take || nontake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),maxsum=0;
        for(int i=0;i<n;i++){
            maxsum+=nums[i];
        }
        int target=maxsum/2;
        if(maxsum%2!=0) return false;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return split(nums,target,n-1,dp);
    }
};