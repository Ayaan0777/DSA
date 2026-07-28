class Solution {
private:
    void dfs(int ind,vector<int> adj[],int v[]){
        v[ind]=1;
        for(auto it: adj[ind]){
            if(!v[it]){
                dfs(it,adj,v);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }
        int v[n];
        for (int i = 0; i < n; i++) v[i] = 0; 
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!v[i]){
                cnt++;
                dfs(i,adj,v);
            }
        }
        return cnt;
    }
};