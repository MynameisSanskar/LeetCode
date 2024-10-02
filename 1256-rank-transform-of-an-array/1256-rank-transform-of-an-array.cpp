class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
     unordered_set<int> s;
     map<int,int> m;
     priority_queue<int,vector<int> ,greater<int>> pq;
     for(auto c:arr){
        pq.push(c);
     } 
     vector<int> v;
     int indx=0;  
     while(!pq.empty()){
        if(s.find(pq.top())!=s.end()){
            m[pq.top()]=indx;
        }
        else{
            m[pq.top()]=++indx;
        s.insert(pq.top());
        }
        pq.pop();
     }
     for(auto c:arr){
        if(m.find(c)!=m.end()){
            v.push_back(m[c]);
        }
     }
     return v;
    }
};