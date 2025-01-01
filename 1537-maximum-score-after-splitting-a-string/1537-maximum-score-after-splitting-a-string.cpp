class Solution {
public:
    int maxScore(string s) {
     int one=0,zero=0;
    //  int temp=stoi(s);
    //  s=to_string(temp);
    //  cout<<s;
     for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            one++;
        }
     }
     if(one==0)
     return 1;
     
     int mn=INT_MIN;
     for(int i=0;i<s.size()-1;i++){
        if(s[i]=='1'){
            one--;
        }
        else{
            zero++;
        }
        mn=max(mn,one+zero);

     }
     
    return mn;
    }
};