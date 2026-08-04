class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,INT_MAX);
         priority_queue<pair<int,int>,vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            if(d>dist[node])    continue;
            for(auto &[next,weight] : adj[node]){
                if(dist[next]>d+weight){
                    dist[next]=d+weight;
                    pq.push({dist[next],next});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)
                return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};