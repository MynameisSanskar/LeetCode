class Solution {
public:
    string bin(int n){
        string s="";
        while(n!=0){
            s=to_string(n%2)+s;
            n/=2;
        }
        cout<<s<<"<-"<<n<<endl;
        return (s);
    }
    int minBitFlips(int start, int goal) {
        string n1=bin(start);
        string n2=bin(goal);
        int mx=max(n1.size(),n2.size());
        while(mx!=n1.size()){
            n1="0"+n1;
        }
        while(mx!=n2.size()){
            n2="0"+n2;
        }
        int xr=0;
        for(int i=0;i<mx;i++){
            xr+=(n1[i]^n2[i]);
        }
        return xr;
    }
};