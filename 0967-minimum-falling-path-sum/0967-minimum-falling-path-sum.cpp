class Solution {
public:
    int f(int i,int j,vector<vector<int>>&m,vector<vector<int>> &dp){
        // base conditon
        if(i==m.size())
        return 0;
        if(j<0 ||j>=m[0].size())
        return INT_MAX;
        if(dp[i][j]!=-1)
        return dp[i][j];
        // main case
        int ld=f(i+1,j-1,m,dp);
        int rd=f(i+1,j+1,m,dp);
        int b=f(i+1,j,m,dp);
        return dp[i][j]=m[i][j]+min({ld,rd,b});

    } 
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n+1,vector<int>(m,0));
        // for(int i=0;i<m;i++){
            // ans=min(ans,f(0,i,matrix,dp));
        // }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int ld=1e9;
                if(j>0)ld=dp[i+1][j-1];
                int rd=1e9;
                if(j<m-1)rd=dp[i+1][j+1];
                int b=dp[i+1][j];
                dp[i][j]=matrix[i][j]+min({ld,rd,b});
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};