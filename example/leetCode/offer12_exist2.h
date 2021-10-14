class Solution {
public:

void dfsExists(vector<vector<char>>& board,
        string word, int col, int row, int level,
        vector<vector<bool>>& vis, bool& flag)
{
    if (level == (word.size() - 1)){
        flag = true;
        return;
    }
    vis[col][row] = true;
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0, -1},{0, 1}};
    for (auto dir : dirs){
        int newC = col + dir[0];
        int newR = row + dir[1];
        bool colFlag = newC >= 0 && newC < board.size();
        bool rowFlag = newR >= 0 && newR < board[0].size();
        if( colFlag && rowFlag && !vis[newC][newR] && (word[level + 1] == board[newC][newR])){
            dfsExists(board, word, newC, newR, level + 1, vis, flag);
            if (flag) {
                return;
            }
        }
    }
    vis[col][row] = false;
    return;
};

bool exist2(vector<vector<char>>& board, string word) {
    if(board.empty() || word.empty()) return false;
    int col = board.size();
    int row = board[0].size();
    vector<vector<bool>> vis(col,vector<bool>(row));
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            if(word[0] == board[i][j]) {
                bool hasPath = false;
                dfsExists(board, word, i, j, 0, vis, hasPath);
                if(hasPath) return true;
            }
        }
    }
    return false;
}
};
