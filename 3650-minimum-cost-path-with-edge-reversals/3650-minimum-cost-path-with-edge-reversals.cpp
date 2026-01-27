class Solution {
public:
    vector<vector<pair<int, int>>> graph;

    int dijkstra(int n) {
        vector<bool> vis(n, false);
        vector<int> dist(n, 1e9);
        
        priority_queue<pair<int,int> > queue;
        queue.push({0, 0});
        dist[0] = 0;

        while(!queue.empty()){
            int u = queue.top().second;
            queue.pop();
            
            if(vis[u]) continue;
            vis[u] = true;

            for(auto [v, w] : graph[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    queue.push({-dist[v], v});
                }
            }
        }

        if(dist[n - 1] == 1e9) return -1;

        return dist[n - 1];
    }

    int minCost(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, 2 * w});
        }
        return dijkstra(n);
    }
};