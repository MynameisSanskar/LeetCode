class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        string no=to_string(x);
        int sum=0;
        for(char c:no){
            sum+=c-'0';
        }
        if(x%sum==0)
        return sum;
        return -1;
    }
};