class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){
                        vis[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
        }
        int nrow[]={-1,0,+1,0};
        int ncol[]={0,+1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nnrow=row+nrow[i];
                int nncol=col+ncol[i];
                if(nnrow>=0 && nnrow<n && nncol>=0 && nncol<m && vis[nnrow][nncol]==0 && grid[nnrow][nncol]==1){
                    vis[nnrow][nncol]=1;
                    q.push({nnrow,nncol});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0)
                    cnt++;
            }
        }
        return cnt;
    }
};