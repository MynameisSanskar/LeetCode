class Solution {
public:
    int findComplement(int num) {
       string binary="";
       while(num!=0){
        binary.insert(binary.begin(),(num%2)+'0');
        num/=2;
       }
       cout<<binary;
    //    reverse(binary.begin(),binary.end());
       for(int i=0;i<binary.size();i++){
        binary[i]=(binary[i]=='1')?'0':'1';
       }
       int n=0; 

       for(int i=0;i<binary.size();i++){
        n=n*2+(binary[i]-'0');
       }
       return n;
    }
};