class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n=nums.size();
        int left=nums[0],right=nums[n-1];
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==t) return mid;
            if(nums[low]<=nums[mid]){
                if(nums[low]<=t && t<nums[mid] ){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                    // left=nums[mid];
                }
            }
            else{

                if(nums[high]>=t && t>nums[mid]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                    // right=nums[mid];
                }
            }

        }
        return -1;
    }
};