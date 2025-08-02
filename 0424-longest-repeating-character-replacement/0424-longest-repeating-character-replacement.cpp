class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,n=s.size(),cnt[26]={},ans=INT_MIN;
        for(;j<n;){
         cnt[s[j++]-'A']++;
         while(j-i-*max_element(cnt,cnt+26)>k) cnt[s[i++]-'A']--;
         ans=max(ans,j-i);
        }
    return ans;
    }

};