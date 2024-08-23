class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        // base case

         if(n<=1)
          return intervals;
        
        // normal case
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            // int j=i-1;
            
            // while(i< n && intervals[i][0]<=intervals[i-1][1] && intervals[i][1]>=intervals[i-1][1]   ){
                // i++;
            // }
    //    if(i>1){ if(intervals[i-2][1]<=intervals[i-1][1]) ans.push_back({intervals[j][0],intervals[i-1][1]});}
    //    else
    //    ans.push_back({intervals[j][0],intervals[i-1][1]});

        //     else
        //     ans.push_back({intervals[i][0],intervals[i][1]});

        //     return ans;
        // }

       if(intervals[i][0]<=ans.back()[1]){
        ans.back()[1]=max(ans.back()[1],intervals[i][1]);
       }
       else{
        ans.push_back(intervals[i]);
       }
    }

    // }
            return ans;
    }
};