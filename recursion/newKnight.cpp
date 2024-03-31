#include <bits/stdc++.h>
#define data array <int, 3>
using namespace std;
const long long N = 10;
int s, t;
bool visited[N][N];

int n = 6;
int dx[8] = {-1, 1, -2, 2, -1, 1, -2, 2};
int dy[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
int ans[N][N];

bool valid(int i, int j) {
    return i >= 1 && j >= 1 && i <= n && j <= n;
}

int degree(int x, int y) {
    int res = 0;
    return min(x - 1, n - x) + min(y - 1, n - y);
    for (int i = 0; i < 8; i ++) {
        int u = x + dx[i], v = y + dy[i];
        if (valid(u, v) && !visited[u][v]) res ++;
    }
    return res;
}

void Try(int x, int y, int step) {

    visited[x][y] = true;
    ans[x][y] = step;

    if (step == n * n) {
        visited[x][y] = false;
        if (abs(x - t)*abs(y - s) != 2) return;

        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++)
                cout << ans[i][j] << ' ';
            cout << '\n';
        }

        exit(0);
    }

    vector <data> save;

        for (int i = 0; i < 8; i ++) {
            int u = x + dx[i];
            int v = y + dy[i];

            if (valid(u, v) && !visited[u][v])
                save.push_back({degree(u, v), u, v});
        }

    sort(save.begin(), save.end());

    for (data &arr: save)
        Try(arr[1], arr[2], step + 1);


    visited[x][y] = false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    Try(t, s, 1);
	return 0;
}