#include <iostream>

using namespace std;

// int ans[8][8];

bool valid(int x, int y, int n) {
    // cout << x << ' ' << y << ' ' << n << '\n';
    return x >= 0 && x < n && y >= 0 && y < n;
}

int degree(int x, int y, int dx[], int dy[], int* ans, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx, ny, n) && ans[nx * n + ny] == 0) {
            cnt ++;
        }
    }
    return cnt;
}

void Try(int x, int y, int dx[], int dy[], int step, int *ans, int n) {
    if (step == n * n) {
        bool isOk = 0;
        for (int i = 0; i < n; i ++) {
            int nX = x + dx[i];
            int nY = y + dy[i];
            if (valid(nX, nY, n) && ans[nX * n + nY] == 1) {
                isOk = 1;
                break;
            }
        }
        cout << isOk << " call\n";
        if (!isOk) return;

        ans[x * n + y] = step;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                cout << ans[i * n + j] << " ";
            }
            cout << '\n';
        }
        // cout << "=============\n";
        delete []ans;
        exit(0);
        return;
    }

    ans[x * n + y] = step;
    // cout << "Step " << step << ": " << x << " " << y << '\n';
    int* tmp = new int[8]{0};
    int* tmpX = new int[8]{0};
    int* tmpY = new int[8]{0};

    int sz = 0;
    int minDegree = n + 1, nX, nY;
    for (int i = 0; i < 8; i ++) {
        // cout << "123";
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx, ny, n) && ans[nx * n + ny] == 0) {
            // cout << "123";
            // Try(nx, ny, dx, dy, step + 1, ans, n);
            int d = degree(nx, ny, dx, dy, ans, n);
            if (d < minDegree) {
                minDegree = d;
                nX = nx;
                nY = ny;
            }
            tmp[sz ++] = d;
            tmpX[sz - 1] = nx;
            tmpY[sz - 1] = ny;
        }
    }

    for (int i = 0; i < sz; i ++) {
        for (int j = i + 1; j < sz; j ++) {
            if (tmp[i] > tmp[j]) {
                swap(tmp[i], tmp[j]);
                swap(tmpX[i], tmpX[j]);
                swap(tmpY[i], tmpY[j]);
            }
        }
    }

    for (int i = 0; i < sz; i ++) {
        Try(tmpX[i], tmpY[i], dx, dy, step + 1, ans, n);
    }

    ans[x * n + y] = 0;
}

int main() {

    int n;
    cin >> n;

    int* ans = new int[n * n]{0};

    int x, y;
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

    cin >> y >> x; x--; y --;
    Try(x, y, dx, dy, 1, ans, n);

    delete[] ans;

    return 0;
}