#include <iostream>
#include <cstring>

using namespace std;

int n, max_height, safe_area_cnt, max_safe_area_cnt;
int arr[100][100], visited[100][100];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

// rain: 현재 내리는 비의 양
void dfs(int y, int x, int rain) {
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
            if (arr[ny][nx] > rain && visited[ny][nx] == 0) {
                visited[ny][nx] = 1;
                dfs(ny, nx, rain);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int y=0; y<n; y++) {
        for (int x=0; x<n; x++) {
            cin >> arr[y][x];
            if (arr[y][x] > max_height) max_height = arr[y][x];
        }
    }


    // i: 내리는 비의 양(모든 경우 조사)
    for (int i=0; i<max_height; i++) {
        // visited 초기화
        memset(visited, 0, sizeof(visited));
        safe_area_cnt = 0;

        for (int y=0; y<n; y++) {
            for (int x=0; x<n; x++) {
                if (visited[y][x] == 0 && arr[y][x] > i) {
                    safe_area_cnt++;
                    dfs(y, x, i);
                }
            }
        }

        if (max_safe_area_cnt < safe_area_cnt) max_safe_area_cnt = safe_area_cnt;
    }

    cout << max_safe_area_cnt;
    return 0;
}
