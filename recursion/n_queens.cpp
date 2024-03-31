#include <iostream>

using namespace std;

bool d1[40], d2[40], c[20];
int r[20];

bool isSafe(int row, int col) {
    if (d1[row + col] || d2[row - col + 20] || c[col]) return false;
    return true;
}

void place(int curRow, int n) {
    if (curRow == n) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (r[i] == j + 1) cout << "Q ";
                else cout << ". ";
            }
            cout << '\n';
        }

        cout << "=============\n";
        return;
    }

    for (int i = 0; i < n; i ++) {
        if (isSafe(curRow, i)) {
            r[curRow] = i + 1;
            d1[curRow + i] = d2[curRow - i + 20] = c[i] = true;
            place(curRow + 1, n);
            d1[curRow + i] = d2[curRow - i + 20] = c[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int board[20][20] = {0};

    place(0, n);

    return 0;
}