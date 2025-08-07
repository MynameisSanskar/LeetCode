class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int maxA=INT_MIN;
        for(int i=0;i<=heights.size();i++){
            while(!s.empty() &&(i==heights.size() || heights[s.top()]>=heights[i])){
                int height=heights[s.top()];
                s.pop();
                int width;
                if(s.empty())width=i;
                else width=i-s.top()-1;
                maxA=max(maxA,width*height);
            }
            s.push(i);
        }
        return maxA;
    }
    
};