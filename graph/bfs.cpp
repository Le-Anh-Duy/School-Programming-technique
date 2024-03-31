#include <iostream>
#include <cstdio>
using namespace std;

struct queue {
    struct node {
        int x, y, val;
        node* pNext;
        node(int _x, int _y, int _val, node* p=nullptr) {
            x = _x;
            y = _y;
            val = _val;
            pNext = p;
        }
    };

    node* pHead, *pTail;

    queue() {
        pHead = pTail = nullptr;
    }

    ~queue() {
        while (pHead) {
            node* p = pHead;
            pHead = pHead->pNext;
            delete p;
        }
    }

    bool is_empty() {
        if (pHead) return false;
        return true;
    }

    void push(int x, int y, int val) {
        node* p = new node(x, y, val, nullptr);
        if (pTail) {
            pTail->pNext = p;
        } else {
            pHead = p;
        }
        pTail = p;
    }

    bool pop(int &x, int &y, int &val) {
        if (pHead == NULL) return false;
        x = pHead->x;
        y = pHead->y;
        val = pHead->val;

        node* p = pHead;
        pHead = pHead->pNext;
        delete p;
        if (!pHead) pTail = nullptr;

        return true;
    }

};

bool bfs(int sX, int sY, int eX, int eY, int **a, int n, int **&ans) {
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    queue q;

    int **f = new int*[n];
    for (int i = 0; i < n; i ++) {
        f[i] = new int[n]{0};
        for (int j = 0; j < n; j ++)
            f[i][j] = -1;
    }

    f[sX][sY] = 0;
    q.push(sX, sY, 0);
    while (!q.is_empty()) {
        int x, y, val;
        bool ok = q.pop(x, y, val);
        // cout << "currently in " << x << ' ' << y << ' ' << val << '\n';
        if (!ok) {
            cout << "error occured\n";
            return false;
        }

        if (x == eX && y == eY) {
            // cout << "Found\n";
            ans = f;
            return true;
        }

        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == 0 && f[nx][ny] == -1) {
                q.push(nx, ny, val + 1);
                f[nx][ny] = val + 1;
            }
        }
    }
    cout << "nothing found\n";
    return false;
}

void trace(int sX, int sY, int eX, int eY, int n, int** ans) {
    bool **path = new bool*[n];
    for (int i = 0; i < n; i ++) {
        path[i] = new bool [n]{0};
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    path[eX][eY] = true;
    // cout << "trace\n";
    while (eX != sX || eY != sY) {
        // cout << "currently at " << eX << ' ' << eY << '\n';
        for (int i = 0; i < 4; i ++) {
            int nx = eX + dx[i];
            int ny = eY + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && ans[nx][ny] == ans[eX][eY] - 1) {
                eX = nx;
                eY = ny;
                path[nx][ny] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (path[i][j])
                ans[i][j] = 1;
            else
                ans[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i ++) {
        delete [] path[i];
    }
    delete [] path;
}

int main() {

    freopen("test.inp", "r", stdin);

    int n;
    cin >> n;

    int sX, sY, eX, eY;
    cin >> sX >> sY >> eX >> eY;
    sX --; sY --; eX --; eY --;

    int **a = new int*[n], **ans = nullptr;
    for (int i = 0; i < n; i ++) {
        a[i] = new int[n]{0};
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> a[i][j];
        }
    }
    // cerr << "calling bfs" << endl;

    bool res = bfs(sX, sY, eX, eY, a, n, ans);
    // cerr << "output bfs" << res << endl;

    if (res) {
        // cerr << "found a way" << endl;

        cout << "The number of steps is: " << ans[eX][eY] << '\n';
        trace(sX, sY, eX, eY, n, ans);
        cout << "The path is:\n";
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }

    } else cout << "No way\n";

    for (int i = 0; i < n; i ++) {
        delete [] a[i];
        if (res)
            delete [] ans[i];
    }

    delete [] a;
    if (res)
        delete [] ans;

    return 0;
}