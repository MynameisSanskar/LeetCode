class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<long long int> v(n+1,0);
        for(auto it:shifts){
            long long int start=it[0];
            long long int end=it[1];
            long long int dr=it[2];
            if(dr==0)
            dr=-1;
            // transform(v.begin()+start,
            //           v.begin()+end+1,
            //           v.begin()+start,
            //           [dr](long long int num){return num+dr;});
            v[start]+=dr;
            v[end+1]-=dr;
            
        }
        for(int i=1;i<n;i++)
        {
        v[i]+=v[i-1];
        cout<<v[i]<<" ";
        }

        string ans="";
        for(int i=0;i<n;i++){
            long long int cur=s[i]-'a';
            cur+=v[i];
            cur%=26;
            if(cur<0)
            cur+=26;
            ans+=(cur+'a');
            
        }
        
        return ans;
    }
};