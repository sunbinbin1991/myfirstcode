class Solution36 {
    vector<bool> visCol;
    vector<bool> visRow;
    int cube[3][3];
public:
      bool checkCol(vector<vector<char>>& board, int i, int j){
        set<char> setRowChar;
        set<char> setColChar;
        for (int k = 0; k < board.size(); ++k) {
            char ch = board[i][k];
            if (ch == '.') continue;
            if (setColChar.find(ch) != setColChar.end()) {
                return false;
            } else {
                setColChar.insert(ch);
            }
        }
        visCol[i] = true;

        for (int k = 0; k < board.size(); ++k) {
            char ch2 = board[k][j];
            if(ch2 == '.') continue;
            if (setRowChar.find(ch2) != setRowChar.end()) {
                return false;
            } else {
                setRowChar.insert(ch2);
            }
        }
      
        visRow[j] = true;
        return true;
    }

    bool checkCube(vector<vector<char>>& board, int i, int j) {
        int cubeCol = i / 3;
        int cubeRow = j / 3;
        set<char> setChar;
        int startCol =  i / 3 * 3;
        int startRow =  j / 3 * 3;
        for (int k = startCol; k < startCol + 3; ++k) {
            for (int l = startRow; l < startRow + 3; ++l) {
                char ch = board[k][l];
                if(ch == '.') continue;
                if (setChar.find(ch) != setChar.end()) {
                    return false;
                } else {
                    setChar.insert(ch);
                }
            }
        }
        cube[cubeCol][cubeRow] = 1;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        memset(cube, -1,sizeof(int) * 3 * 3);
        visCol.resize(9, -1);
        visRow.resize(9, -1);
        // for (int j = 0; j < 3; ++j) {
        //     for (int i = 0; i < 3; ++i) {
        //         cout << cube[j][i] << ' ';
        //     }
        //     cout << endl;
        // }

        for (int k = 0; k < board.size(); ++k) {
            for (int i = 0; i < board[0].size(); ++i) {
                // printf("k:%d j:%d: flag:%d\n", k, i, checkCol(board,k,i));
                // printf("k:%d j:%d: flag1:%d\n", k, i, visCol[k]);
                // printf("k:%d j:%d: flag2:%d\n", k, i, visRow[i]);
                // printf("k:%d j:%d: flag3:%d\n", k, i, cube[k/3][i/3]);
                if(visCol[k] && visRow[i] && (cube[k/3][i/3] == 1)){
                    continue;
                }
                if (checkCol(board,k,i) && checkCube(board,k,i)) {
                    continue;
                } else {
                    return false;
                }
            }
        }

        // for (int j = 0; j < 3; ++j) {
        //     for (int i = 0; i < 3; ++i) {
        //         cout << cube[j][i] << ' ';
        //     }
        //     cout << endl;
        // }
        return true;
    }
};
