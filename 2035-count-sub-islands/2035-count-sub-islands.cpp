class Solution {
public:
 int dfs(int i, int j, vector<vector<int>> &grid2, vector<vector<int>> &grid1) {
    if (i < 0 || j < 0 || i >= grid2.size() || j >= grid2[0].size() || grid2[i][j] == 0)
        return 1;
    if (grid1[i][j] == 0 && grid2[i][j] == 1)
        return 0;

    // Mark the cell as visited
    grid2[i][j] = 0;

    // Perform DFS on all four directions
    return dfs(i + 1, j, grid2, grid1) *
           dfs(i - 1, j, grid2, grid1) *
           dfs(i, j + 1, grid2, grid1) *
           dfs(i, j - 1, grid2, grid1);
}

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();
        int p=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && grid1[i][j]==1){
                    p+=(dfs(i,j,grid2,grid1)>=1);
                }
            }
        }
        return p;
    }
};