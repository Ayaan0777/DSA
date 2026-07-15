class Solution {
public:
    int find(int i,int j,string& w1, string& w2,vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]) return dp[i][j]=find(i-1,j-1,w1,w2,dp);
        return dp[i][j]= 1+min(find(i-1,j,w1,w2,dp),
        min(find(i,j-1,w1,w2,dp)
        ,find(i-1,j-1,w1,w2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return find(n-1,m-1,word1,word2,dp);
    }
};