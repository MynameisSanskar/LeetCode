class Solution {
public:
    int rev(int x){
        string s=to_string(x);
        reverse(s.begin(),s.end());
        return stoi(s);
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>m;
        int mn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])){
                mn=min(mn,abs(i-m[nums[i]]));
            }
            m[rev(nums[i])]=i;
        }
        return mn==INT_MAX?-1:mn;
    }
};