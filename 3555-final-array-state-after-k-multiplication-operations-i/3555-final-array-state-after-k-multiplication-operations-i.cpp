class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k>0){
            auto temp=pq.top();
            pq.pop();
            pq.push({temp.first*multiplier,temp.second});
            k--;
        }
        vector<int> v(nums.size());
        while(!pq.empty()){
            auto [node,idx]=pq.top();
            pq.pop();
            v[idx]=node;
        }
    return v;
    }
};