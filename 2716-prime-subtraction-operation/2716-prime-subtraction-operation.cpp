class Solution {
public:
    void sieve_algo(vector<bool> &isPrime,int n){
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i*i<n;i++){
            for(int j=2*i;j<n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<bool> isPrime(1001,true);
        sieve_algo(isPrime,1001); 
        vector<int> prime;
        for(int i=0;i<1001;i++){
            if(isPrime[i])
            prime.push_back(i);
        }
        int n=nums.size();
        int prev=nums[n-1];
        int flag=1;
        
        for(int i=n-2;i>=0;i--){
            if(prev>nums[i]){
                prev=nums[i];
                continue;
            }
            flag=0;
            for(int sub=0;sub<prime.size() && prime[sub]<nums[i];sub++){
                if(prev>nums[i]-prime[sub]){
                    prev=nums[i]-prime[sub];
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            break;
        }
        return flag;
    }
};