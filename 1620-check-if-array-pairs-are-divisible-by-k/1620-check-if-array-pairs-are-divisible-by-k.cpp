class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> v(k,0);
        for(int i=0;i<n;i++){
            int rem=arr[i]%k;
            if(rem<0)
            rem+=k;
            v[rem]++;
        }
        if(v[0]%2==1)
        return 0;
        for(int i=1;i<=k/2;i++){
            if(v[i]!=v[k-i])
            return 0;
        }
        return 1;
    }
};