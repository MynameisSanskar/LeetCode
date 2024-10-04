class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
    long long int a=0;
    int n=skill.size();
    sort(skill.begin(),skill.end());
    int prev;
    for(int i=0;i<(n/2);i++){
     if(i==0){
        prev=skill[i]+skill[n-i-1];
        a=skill[i]*skill[n-1-i];
     }
     else{
        if(prev==skill[i]+skill[n-i-1]){
         prev=skill[i]+skill[n-i-1];
         a+=skill[i]*skill[n-1-i]; }
         else
         return -1;
     }
    }
    return a;    
    }
};