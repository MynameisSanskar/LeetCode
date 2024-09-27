class MyCalendarTwo {
public:
    vector<pair<int,int>> v1;
    vector<pair<int,int>> v2;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto &[s,e]:v2){
            if(max(s,start)<min(e,end)){
                return 0;
            }
        }
        for(auto &[s,e]:v1){
            if(max(s,start)<min(e,end)){
                v2.push_back({max(s,start),min(e,end)});
            }
        }
        v1.push_back({start,end});
        return 1;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */