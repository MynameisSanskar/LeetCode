class AllOne {
public:
    unordered_map<string,int>m;
    set<pair<int,string>> s;
    AllOne() {
        m.clear();
        s.clear();
    }
    
    void inc(string key) {
        if(m[key]==0){
            m[key]++;
            s.insert({m[key],key});
        }
        else{
         s.erase({m[key],key})  ;
         m[key]++;
         s.insert({m[key],key});
        }
    }
    
    void dec(string key) {
        if(m[key]==1){
            s.erase(s.find({m[key],key}));
            m.erase(key);
        }
        else{
            s.erase(s.find({m[key],key}));
            m[key]--;
            s.insert({m[key],key});
        }

    }
    
    string getMaxKey() {
        if(!s.empty())
        return s.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if(!s.empty())
        return s.begin()->second;
        return ""; 
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */