class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0] = 1;
        int mx = 0;

        while (!pq.empty()) {
            auto cr = pq.top();
            pq.pop();
            int cur = cr[0], i = cr[1], j = cr[2];
            mx = max(mx, cur);
            if (i == n-1 && j == m-1) return mx;

            for (auto &d : dir) {
                int nx = i + d[0];
                int ny = j + d[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                pq.push({grid[nx][ny], nx, ny});
            }
        }
        return mx;
    }
};
