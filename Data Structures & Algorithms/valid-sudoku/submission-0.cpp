class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector <unordered_set <char>> rows(9);
        vector <unordered_set <char>> clms(9);
        vector <unordered_set <char>> boxes(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];

                if (val == '.') {
                    continue;
                }

                int box = (r / 3) * 3 + (c / 3); // to check if duplcate exists in given 3*3 box or not

                if (rows[r].count(val) || clms[c].count(val) || boxes[box].count(val)) {
                    return false; // cz this means sudoku contains duplicate
                }

                rows[r].insert(val);
                clms[c].insert(val);
                boxes[box].insert(val);
            }
        }

        return true;
    }
};
