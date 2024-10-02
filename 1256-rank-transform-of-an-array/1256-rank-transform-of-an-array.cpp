class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    using p=pair<int,int>;
    priority_queue<p,vector<p>,greater<p>> pq;
    for(auto c=0;c<arr.size();c++){
        pq.push({arr[c],c});
    }
    int indx=1;
    
    while(!pq.empty()){
        int val=pq.top().first;
        int index=pq.top().second;
        pq.pop();
        arr[index]=indx;
        int next=pq.top().first;
        if(val!=next)
        indx++;
    }
    return arr;
    }
};