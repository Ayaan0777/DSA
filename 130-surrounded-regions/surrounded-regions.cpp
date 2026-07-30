class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X')
                    vis[i][j]=1;
                else if(i ==n-1 && board[i][j] == 'O'|| j ==m-1 && board[i][j]=='O' || i==0 && board[i][j] == 'O' || j==0 && board[i][j] == 'O'){
                    q.push({i,j});
                    vis[i][j]=1;
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
                if(nnrow>=0 && nnrow<n && nncol>=0 && nncol<m && board[nnrow][nncol] == 'O' && vis[nnrow][nncol] == 0){
                    vis[nnrow][nncol]=1;
                    q.push({nnrow,nncol});
                }
            }
        }
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == 'O' && vis[i][j] == 0)
                        board[i][j] = 'X';
                }
            }
    }
};