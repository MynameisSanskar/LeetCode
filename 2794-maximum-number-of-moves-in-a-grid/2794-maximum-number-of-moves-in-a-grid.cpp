class Solution {
public:
    int f(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>&dp){
        // base case
        if (i < 0 || i >= n || j >= m) {
            return 0;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];

        // main case
        int cur=grid[i][j];
        int right=0;
        if(i<n && j+1<m && grid[i][j+1]>cur)
        right=f(i,j+1,n,m,grid,dp);
        int up=0;
         if(i-1>=0 && j+1<m && grid[i-1][j+1]>cur)
        up=f(i-1,j+1,n,m,grid,dp);
        int down=0;
         if(i+1<n && j+1<m && grid[i+1][j+1]>cur)
        down=f(i+1,j+1,n,m,grid,dp);

        return dp[i][j]=1+max({right,up,down});
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        int mx=-1e9;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            int cur=f(i,0,n,m,grid,dp);
            mx=max(mx,cur);
        }
        return mx==-1e9?0:mx-1;
    }
};