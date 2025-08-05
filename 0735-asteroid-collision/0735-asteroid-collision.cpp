class Solution {
public:
    bool samesign(int a,int b){
        if(a<0 && b<0) return 1;
        else if(a>0 && b>0) return 1;
        return 0;
    }
   vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int c : asteroids) {
        // Case 1: No collision
        if (st.empty() || (st.top() < 0 && c > 0) || samesign(st.top(), c)) {
            st.push(c);
        }
        // Case 2: Collision handling
        else {
            while (!st.empty() && st.top() > 0 && st.top() < abs(c)) {
                st.pop();
            }

            if (st.empty() || st.top() < 0) {
                st.push(c);
            } else if (st.top() == abs(c)) {
                st.pop();
            }
        }
    }

    // Construct result vector from stack
    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        result[i] = st.top();
        st.pop();
    }

    return result;
}

};