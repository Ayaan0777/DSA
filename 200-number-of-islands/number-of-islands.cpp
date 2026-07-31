class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
         int nnrow[]={-1,0,+1,0};
        int nncol[]={0,+1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vis[i][j]=1;
                    while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+nnrow[i];
                int ncol=col+nncol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
                }
            }
        }
       return cnt;
    }
};