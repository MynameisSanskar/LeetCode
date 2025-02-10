class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
     for(auto &x:s){
        // character
        if(!isdigit(x)){
            st.push(x);
        }
        // digit
        else if(isdigit(x) && !st.empty())
        {
            st.pop();
        }
        else{
            st.push(x);
        }
     }
     string res="";
        while(!st.empty()){
            res=st.top()+res;st.pop();
        }
        return res;
     
    }
};