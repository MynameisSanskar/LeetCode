class Solution {
public:
    int f(int indx,int last,vector<int> &nums,vector<vector<int>> &dp){
        // base case
        if(indx<0){
            return 0;
        }
        if(dp[indx][last-1]!=-1)
        return dp[indx][last-1];

        // main case
        int notTake=f(indx-1,last,nums,dp);
        int take=-1e9;
        if(last==nums.size() || nums[indx]<nums[last])
            take=1+f(indx-1,indx,nums,dp);
        // return
        return dp[indx][last-1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int indx = n - 1; indx >= 0; indx--) {
        for (int last = indx - 1; last >= -1; last--) {
            // Not taking the current element
            //  int notTake=f(indx-1,last,nums,dp);
            int notTake = dp[indx+1][last + 1];

            // Taking the current element
            int take = 0;
            if (last == -1 || nums[indx] > nums[last]) {
                take = 1 + dp[indx + 1][indx + 1];
            }

            dp[indx][last + 1] = max(take, notTake);
        }
    }

    return dp[0][0];
}


};