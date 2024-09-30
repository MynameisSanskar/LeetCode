class CustomStack {
public:
    vector<int> v;
    int maxSize;
    CustomStack(int maxSize) {
        // v.resize(maxSize);
        this->maxSize=maxSize;
    }
    
    void push(int x) {
       if(v.size()<maxSize) 
        v.push_back(x);
        cout<<"pushed"<<x<<endl;
    }
    
    int pop() {
        if(v.empty()==1)
        return -1;
        int n=v.back();
        v.pop_back();
        return n;
    }
    
    void increment(int k, int val) {
        int n=v.size();
        for(int i=0;i<min(n,k);i++){
            cout<<v[i]<<"-";
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */