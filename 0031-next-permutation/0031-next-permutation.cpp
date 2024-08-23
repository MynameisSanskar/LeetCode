class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Find the pivot
        int indx = -1;
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                indx = i;
                break;
            }
        }
        
        // If no pivot found, reverse the entire sequence
        if(indx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Find the rightmost element greater than the pivot
        for(int i = nums.size() - 1; i > indx; i--) {
            if(nums[indx] < nums[i]) {
                swap(nums[indx], nums[i]);
                break;
            }
        }
        
        // Reverse the sequence from the pivot index + 1 to the end
        reverse(nums.begin() + indx + 1, nums.end());
    }
};
