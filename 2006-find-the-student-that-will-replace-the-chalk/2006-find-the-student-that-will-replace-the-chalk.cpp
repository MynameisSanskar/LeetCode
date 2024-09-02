class Solution {
public:
    int chalkReplacer(vector<int>& c, int k) {
       k%=accumulate(c.begin(),c.end(),0l);
       
        
            for(int i=0;i<c.size();i++){
                if(k-c[i]<0)
                return i;
                else if(k-c[i]==0){
                    return (i+1)%c.size();
                }
                k=k-c[i];
            }
        
        return 0;
    }
};