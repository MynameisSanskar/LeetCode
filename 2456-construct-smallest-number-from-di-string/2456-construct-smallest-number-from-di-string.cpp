class Solution {
public:
    string smallestNumber(string pattern) {
        string res="",st="";
        for(auto i=0;i<pattern.size()+1;i++){
            st.push_back('0'+(i+1));
            while(st.size()>0 &&(i==pattern.size() || pattern[i]=='I')){
                res.push_back(st[st.size()-1]);
                st.pop_back();
            }
        }
        return res;
    }
};