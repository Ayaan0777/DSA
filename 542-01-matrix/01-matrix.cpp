class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int nrow[]={-1,0,+1,0};
        int ncol[]={0,+1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dis[row][col]=steps;
            for(int i=0;i<4;i++){
                int nnrow=row+nrow[i];
                int nncol=col+ncol[i];
                if(nnrow>=0 && nnrow<n && nncol>=0 && nncol<m && vis[nnrow][nncol]==0){
                    vis[nnrow][nncol]=1;
                    q.push({{nnrow,nncol},steps+1});
                }
            }
        }
        return dis;
    }
};