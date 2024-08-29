class Disjoint{
    vector<int> parent,size;
    public:
    Disjoint(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUPar(int node){
        if(node==parent[node])
        return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int up_u=findUPar(u);
        int up_v=findUPar(v);
        if(up_u==up_v)
        return ;
        if(size[up_u]<size[up_v]){
            parent[up_u]=up_v;
            size[up_v]+=size[up_u];
        }
        else{
            parent[up_v]=up_u;
            size[up_u]+=size[up_v];
        }
    }


};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        Disjoint ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(stones[i][0]==stones[j][0] ||stones[i][1]==stones[j][1]){
                    ds.unionBySize(i,j);
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i){
                c++;
            }
        }
        return n-c;
    }
};