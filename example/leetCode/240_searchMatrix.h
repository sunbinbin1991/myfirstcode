class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int chooseX = col - 1;
        int chooseY = 0;
        while(chooseX >= 0 && chooseX < col && chooseY < row && chooseY >= 0) {
            if(matrix[chooseY][chooseX] < target) {
                chooseY += 1;
            } else if(matrix[chooseY][chooseX] > target) {
                chooseX -= 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
