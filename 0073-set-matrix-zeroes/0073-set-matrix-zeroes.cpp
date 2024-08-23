class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    
 int rows = matrix.size();
    int cols = matrix[0].size(); // Assuming matrix is not empty
    
    stack<pair<int,int>> s;

    // Find zero elements and push their indices onto the stack
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] == 0) {
                s.push({i, j});
            }
        }
    }

    // Process the stack to set rows and columns to zero
    while(!s.empty()) {
        int row = s.top().first;
        int col = s.top().second;
        s.pop();

        // Set entire row to zero
        for(int k = 0; k < cols; k++) {
            matrix[row][k] = 0;
        }

        // Set entire column to zero
        for(int l = 0; l < rows; l++) {
            matrix[l][col] = 0;
        }
    }

    }
};