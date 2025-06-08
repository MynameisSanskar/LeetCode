class Solution {
public:
    void dfs(int cur,vector<int> &v,int n){
        if(cur>n ||v.size()>=n){
            return ;
        }
        
        v.push_back(cur);
        int k=cur;
       
        for(int i=0;i<=9;i++){
            k=k*10+i;

            dfs(k,v,n);
            k=cur;
        }

    }
    vector<int> lexicalOrder(int n) {
      vector<int> v;
        for(int i=1;i<=n;i++){
            // v.push_back(i);
            dfs(i,v,n);
        }
        
        return v;
    }
};