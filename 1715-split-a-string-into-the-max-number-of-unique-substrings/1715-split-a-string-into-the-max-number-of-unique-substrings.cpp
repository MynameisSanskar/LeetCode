class Solution {
public:
    int a=0;
    void f(int indx,int n,string s, unordered_set<string> &s1){
        if(indx==n){
            int sz=s1.size();
            a=max(a,sz);
            return ;
        }
        string sub="";
        for(int i=indx;i<n;i++){
            sub+=s[i];
            if(s1.find(sub)==s1.end()){
                s1.insert(sub);
                f(i+1,n,s,s1);
                s1.erase(sub);
            }

        }
        
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> s1;
        int n=s.size();

         f(0,n,s,s1);
         return a;
    }
};