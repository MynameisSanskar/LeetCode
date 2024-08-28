class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
         int p=0;
        int row=grid.size();
        int col=grid[0].size();
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1')
               { p+=dfs(grid,i,j);
                  c++;
               }
            }
        }
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[i].size();j++){
               
        //       c=max(c,grid[i][j]-'0');
        //     }
        // }
        return c;
    }
    int dfs(vector<vector<char>> &m,int i, int j){
        
        if(i<0 || i>=m.size() || j<0 || j>=m[0].size()|| m[i][j]=='0'){
           return 1;
        }
        if(m[i][j]=='@')
            return 0;

        m[i][j]='@';
        return (dfs(m,i+1,j)+
        dfs(m,i-1,j)+
        dfs(m,i,j+1)+
        dfs(m,i,j-1));
        
    
    }
};