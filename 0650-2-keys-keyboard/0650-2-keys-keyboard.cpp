class Solution {
public:
    int f(int num,int cpy,int n){
        if(num==n)
        return 0;
        if(num+cpy>n)
        return 2000;
        int c=2+f(num+num,num,n);
        int p=1+f(num+cpy,cpy,n);
        return min(c,p);
    }
    int minSteps(int n) {
        if(n<=1)
        return 0;
     return 2+f(2,1,n);   
    }
};