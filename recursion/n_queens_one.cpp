#include <iostream>

using namespace std;

void place(int n) {
    char board[20][20] = {0};
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            board[i][j] = '.';
    int r = 0;
    for (int c = 0; c < n; c ++) {
        board[r][c] = 'Q';
        r -= 2;
        if (r < 0) r += n;
        r %= n;
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    int n = 5;
    cin >> n;
    place(n);
}