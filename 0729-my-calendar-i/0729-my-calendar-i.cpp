class MyCalendar {
    map<int, int> m; // Stores intervals with start as key and end as value
public:
    MyCalendar() {}

    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int ongoing=0;
        for(auto c:m){
            ongoing+=c.second;
            if(ongoing>=2){
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */