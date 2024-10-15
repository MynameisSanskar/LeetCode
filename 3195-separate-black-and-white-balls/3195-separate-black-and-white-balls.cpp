class Solution {
public:
    long long minimumSteps(string s) {
        long long  c=0;
            long long int k=0;
        for(long long int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                k++;
            }
            else{
                c+=k;
            }
        }
        
             return c; 
    }
};