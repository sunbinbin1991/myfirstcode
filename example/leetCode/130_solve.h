class Solution130 {
private:
    vector<vector<bool>> vis;
public:
    void dfsBoard(vector<vector<char>>& board,
                  vector<vector<pair<int, int>>>& paths,
                  vector<pair<int, int>>& path,
                  int col, int row,
                  int i, int j) {
        if(i == col - 1 || j == row - 1 || i == 0 || j == 0){
            pair<int,int> tp{i ,j};
            path.push_back(tp);
            paths.push_back(path);
            return;
        }

//        board[i][j] = 'X';
        vis[i][j] = true;
        if(i - 1 >= 0 && i - 1 <= col && j >= 0 && j <= row - 1) {
            if (board[i-1][j] == 'O' && !vis[i-1][j]) {
                pair<int,int> tp{i - 1,j};
                cout <<path.size()<< endl;
                path.push_back(tp);
                vis[i-1][j]= true;
                dfsBoard(board, paths, path, col, row, i - 1, j);
                path.pop_back();
                vis[i-1][j]= false;
            }
        }

        if(i + 1 >= 0 && i + 1 <= col -1 && j >= 0 && j <= row - 1) {
            if (board[i+1][j] == 'O' && !vis[i+1][j]) {
                pair<int,int> tp{i + 1,j};
                path.push_back(tp);
                vis[i+1][j]= true;
                dfsBoard(board, paths, path, col, row, i + 1, j);
                path.pop_back();
                vis[i+1][j]=false;
            }
        }

        if(i >= 0 && i <= col - 1 && j - 1 >= 0 && j - 1 <= row - 1) {
            if (board[i][j - 1] == 'O' && !vis[i][j-1]) {
                pair<int,int> tp{i ,j - 1};
                path.push_back(tp);
                vis[i][j-1]= true;
                dfsBoard(board, paths, path, col, row, i, j - 1);
                path.pop_back();
                vis[i][j-1]=false;
            }
        }

        if(i >= 0 && i <= col - 1 && j + 1 >= 0 && j + 1 <= row - 1) {
            if (board[i][j+1] == 'O'&& !vis[i][j+1]) {
                pair<int,int> tp{i ,j + 1};
                path.push_back(tp);
                vis[i][j+1]= true;
                dfsBoard(board, paths, path, col, row, i, j + 1);
                path.pop_back();
                vis[i][j+1]= false;
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int col = board.size();
        int row = board[0].size();
        vis.resize(col, vector<bool>(row));
        vector<vector<pair<int, int>>> paths;
        vector<pair<int, int>> path;
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < row; ++j) {
                char  ch = board[i][j];
                if(ch == 'X') {
                    continue;
                }
                dfsBoard(board,paths,path, col, row, i, j);
            }
        }
        for (int k = 0; k < col; ++k) {
            for (int j = 0; j < row; ++j) {
                board[k][j] = 'X';
            }
        }
        for(auto pts: paths) {
            for (int i = 0; i < pts.size(); ++i) {
                cout <<pts[i].first  <<" == " <<pts[i].second <<endl;
                board[pts[i].first][pts[i].second] = 'O';
            }
        }
    }

};


void test_solve(){
    Solution130 sl;
    vector<vector<char>> board = {
            {'X','X','X','X'},
            {'X','O','O','X'},
            {'X','X','O','X'},
            {'X','O','X','X'}};

    sl.solve(board);
    printCharVec(board);

}

void test_solve2(){
    Solution130 sl;
    vector<vector<char>> board = {
            {'O','O','O','O'},
            {'O','O','O','O'},
            {'O','O','O','O'},
            {'O','O','O','O'}};

    sl.solve(board);
    printCharVec(board);

}
