class MyCalendarTwo {
public:
map<int,int> m;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int ongoing=0;
        for(auto c:m){
            ongoing+=c.second;
            if(ongoing>=3){
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */