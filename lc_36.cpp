#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

char flag[10] = {0};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, k, m;
        for (i = 0; i < 9; i++) {
            memset(flag, 0, sizeof(flag));
            for (j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (flag[board[i][j] - '0'])
                    return false;
                flag[board[i][j] - '0'] = 1;
            }
        }

        for (i = 0; i < 9; i++) {
            memset(flag, 0, sizeof(flag));
            for (j = 0; j < 9; j++) {
                if (board[j][i] == '.')
                    continue;
                if (flag[board[j][i] - '0'])
                    return false;
                flag[board[j][i] - '0'] = 1;
            }
        }

        for (k = 0; k < 9; k += 3) {
            for (m = 0; m < 9; m += 3) {
                memset(flag, 0, sizeof(flag));
                for (i = k; i < k + 3; i++) {
                    for (j = m; j < m + 3; j++) {
                        if (board[i][j] == '.')
                            continue;
                        if (flag[board[i][j] - '0'])
                            return false;
                        flag[board[i][j] - '0'] = 1;
                    }
                }
            }
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}