class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        long long int s=nums[0],mx=nums[0];
        for(int i=1;i<nums.size();i++){
            mx=max(mx,s);
            if(nums[i-1]<nums[i])
            {s+=nums[i];
            }
            else{
                s=nums[i];
            }
            mx=max(mx,s);
        }
        return mx;
    }
};