class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<int,double>,vector<pair<int,double>>,greater<pair<int,double>>>pq;
        pq.push({start,1.0});
        vector<double> dist(n,INT_MIN);
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            for(auto it:adj[cur.first]){
                auto u=it.first;
                auto cost=it.second;
                if(cur.second*cost>dist[u]){
                    dist[u]=cur.second*cost;
                    pq.push({u,dist[u]});
                }

            }
        }
        if(dist[end]==INT_MIN)
        return 0.0;
        return dist[end];
    }
};