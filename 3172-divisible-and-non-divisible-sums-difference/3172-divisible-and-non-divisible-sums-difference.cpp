class Solution {
public:
    int differenceOfSums(int n, int m) {
       long long int a=0,b=0;
       for(auto i=1;i<=n;i++){
        if(i%m!=0)
        a+=i;
        else
        b+=i;
       }
       return a-b;
    }
};