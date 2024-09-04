class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
     vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
     unordered_map<string,int>m;
     for(auto c:obstacles){
        m[to_string(c[0])+" "+to_string(c[1])]++;
     }
     int x=0,y=0,d=0,res=0; 
     for(int i=0;i<commands.size();i++){
        if(commands[i]==-1){
            d=(d+1)%4;

        }
        else if(commands[i]==-2){
            d=(d+3)%4;
        }
        else{
            for(int j=0;j<commands[i];j++){
                if(m.find(to_string(x+dir[d][0])+" "+to_string(y+dir[d][1]))==m.end())
                {x+=dir[d][0];
                y+=dir[d][1];}
                else
                break;
            }
        }
res=max(res,x*x+y*y);
     }   
     return res;
    }
};