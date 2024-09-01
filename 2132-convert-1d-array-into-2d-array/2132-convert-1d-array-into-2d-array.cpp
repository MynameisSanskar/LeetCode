class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> v(m,vector<int>(n));
        cout<<"m:"<<m<<"n:"<<n<<endl;
        if(m*n!=original.size())
        return {};
        for(int i=0;i<original.size();i++){
            cout<<"row"<<i/m;
            cout<<"col"<<i%n;
            int row=i/n;
            int col=i%n;
            v[row][col]=original[i];
        }
        return v;
    }
};