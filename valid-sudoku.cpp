#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool chkSud(map<char, int>& m) {
        for (char c = '1'; c <= '9'; c++) {
            if (m[c] > 1) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        for (int i = 0; i < 9; i++) {
            map<char, int> m;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.')
                    m[board[i][j]]++;
            }
            if (!chkSud(m)) return false;
        }

        // column
        for (int i = 0; i < 9; i++) {
            map<char, int> m;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.')
                    m[board[j][i]]++;
            }
            if (!chkSud(m)) return false;
        }

        // 3x3 box
        for (int boxRow = 0; boxRow < 9; boxRow+=3) {
            for (int boxCol = 0; boxCol < 9; boxCol+=3) {
                map<char, int> m;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char ch = board[boxRow + i][boxCol + j];
                        if (ch != '.')
                            m[ch]++;
                    }
                }
                if (!chkSud(m)) return false;
            }
        }

        return true;
    }
};    