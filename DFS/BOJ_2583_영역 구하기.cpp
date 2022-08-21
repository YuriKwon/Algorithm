#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int m, n, k, cnt, max_size;
int arr[101][101];
int visited[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector <int> result;

void dfs(int y, int x, int depth) {
    visited[y][x] = 1;
    cnt++; // 색칠 칸 개수

    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >=0 && ny <m && nx >=0 && nx < n && visited[ny][nx] != 1 && arr[ny][nx] != 1) {
            dfs(ny, nx, depth + 1);
        }
    }
}

int main() {
    cin >> m >> n >> k;
    for (int i=0; i<k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y=y1; y<y2; y++) {
            for (int x=x1; x<x2; x++) {
                arr[y][x] = 1;
            }
        }
    }

    for (int y=0; y<m; y++) {
        for (int x=0; x<n; x++) {
            if (visited[y][x] != 1 && arr[y][x] == 0) {
                cnt = 0;
                dfs(y, x, 1);
                result.push_back(cnt);
            }
        }
    }
    sort(result.begin(), result.end());
    int size = result.size();
    cout << size << endl;
    for (int i=0; i<size; i++) {
        cout << result[i] << " ";
    }
    return 0;
}

// depth로 풀었다가 잘 안돼서, https://minocode.tistory.com/31 여기 참고
