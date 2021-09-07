  void dfsLand(vector<vector<int>>& grid, int i, int j, int row, int col, int& landArea) {
        if(grid[i][j] == 0){
            return;
        }

        landArea++;
        grid[i][j] = 0;
        // up down left right
        if(i - 1 >= 0 && i - 1 <= row - 1 && j >= 0 && j <= col - 1){
            dfsLand(grid,i - 1, j, row, col,landArea);
        }

        if(i + 1 >= 0 && i + 1 <= row - 1 && j >= 0 && j <= col - 1){
            dfsLand(grid,i + 1, j, row, col,landArea);
        }

        if(i >= 0 && i <= row - 1 && j - 1 >= 0 && j - 1 <= col - 1){
            dfsLand(grid,i, j - 1, row, col,landArea);
        }

        if(i >= 0 && i <= row - 1 && j + 1 >= 0 && j + 1 <= col - 1){
            dfsLand(grid,i, j + 1, row, col,landArea);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int ans = INT_MIN;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int landArea = 0;
                if (grid[i][j]) {
                    dfsLand(grid, i, j, row, col, landArea);
                    // cout << "L: "<< landArea << endl;
                    ans = max(ans, landArea);
                }
            }
        }
        return ans == INT_MIN ? 0: ans;
    }
