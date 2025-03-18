class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int start=0,len=0,usedBits=0;
        for(int end=0;end<nums.size();end++){
            // shrink 
            while((nums[end] & usedBits)!=0){
                   usedBits^=nums[start++]; 
            }
            usedBits|=nums[end];
            len=max(len,end-start+1);
        }
        return len;
    }
};