class NumberContainers {
public:
unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
unordered_map<int,int> m1; 
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        m1[index]=number;
        m[number].push(index);
    }
    
    int find(int num) {
       if(m.find(num)!=m.end()){
        auto &minheap=m[num];
        while(!minheap.empty()){
            int index=minheap.top();
            if(m1[index]==num){
                return index;
            }
            minheap.pop();
        }
       }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */