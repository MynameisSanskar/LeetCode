class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        // vector<vector<int>> adj(n);
        unordered_map<string,vector<string>> adj;
        for(auto word:wordList){
        for(int i=0;i<word.size();i++){
            string pattern=word.substr(0,i)+"*"+word.substr(i+1);
            adj[pattern].push_back(word);
        }
        }
        queue<string> q;
        unordered_set<string>vis {beginWord};
        q.push(beginWord);
        int res=0;
        while(!q.empty()){
            int sz=q.size();
            res++;
            for(int j=0;j<sz;j++){
            string word=q.front();
            q.pop();
            if(word==endWord)
            return res;
            
            for(int i=0;i<word.size();i++){
            string pattern=word.substr(0,i)+"*"+word.substr(i+1);
            for(auto ngbh:adj[pattern]){
                if(vis.find(ngbh)==vis.end()){
                    vis.insert(ngbh);
                    q.push(ngbh);
                }
            }
        
            }
            }

        }
        return 0;
    }
};
