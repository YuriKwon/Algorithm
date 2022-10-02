#include <iostream>
#include <cstring>
using namespace std;

int t, m, n, k, y, x;
int arr[51][51];
int visited[51][51]; // 1이면 방문
int num; // 배추 덩어리 수 = 필요한 지렁이 수
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void dfs(int y, int x) {
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && nx >= 0 && ny <= n && nx <= m) {
            if (arr[ny][nx] == 1 && visited[ny][nx] == 0) {
                visited[ny][nx] = 1;
                dfs(ny, nx);
            }
        }
    }
}
int main() {
    cin >> t;
    for (int i=0; i<t; i++) {
        // arr 초기화
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        num = 0;
        cin >> m >> n >> k;
        for (int j=0; j<k; j++) {
            cin >> x >> y;
            arr[y][x] = 1;
        }

        for (int y=0; y<n; y++) {
            for (int x=0; x<m; x++) {
                if (visited[y][x] == 0 && arr[y][x] == 1) {
                    visited[y][x] = 1;
                    dfs(y, x);
                    num++;
                }
            }
        }
        cout << num << "\n";

    }
    return 0;
}
