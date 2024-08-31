class Solution {
public:
    int eq(int x,int y){
        string s1=to_string(x),s2=to_string(y);
        int n=s1.size(),m=s2.size();
        int maxLen=max(n,m);
        while(n!=maxLen){
            s1="0"+s1;
            n++;
        }
        while(m!=maxLen){
            s2="0"+s2;
            m++;
        }
        unordered_map<char,int> mp1,mp2;
        int diff=0;
        for(int i=0;i<n;i++){
            if(diff>2)
            return 0;
            diff+=(s1[i]!=s2[i]);
            mp1[s1[i]]++,mp2[s2[i]]++;
        }
        return diff<=2 && mp1==mp2;
    }
    int countPairs(vector<int>& nums) {
        int c=0;
     for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            c+=eq(nums[i],nums[j]);
        }
     }
     return c;
    }
};