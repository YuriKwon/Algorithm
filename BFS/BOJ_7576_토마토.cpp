#include <iostream>
#include <queue>
using namespace std;

int m, n;
int map[1001][1001];
int visited[1001][1001];
struct Node { int y; int x;};
queue<Node> q;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int maxDay; // 최대 일 수

void BFS() {
  while(!q.empty()) {
    int curY = q.front().y;
    int curX = q.front().x;
    q.pop();

    for (int i=0; i<4; i++) {
      int ny = curY + dy[i];
      int nx = curX + dx[i];

      if (ny < 0 || ny >= m || nx < 0 || nx >= n) {
        continue;
      } else if (map[ny][nx] == -1) {
        continue;
      } else if (visited[ny][nx] == 1) {
        // 방문한 적이 있더라도, 현재 지점에서의 일자가 더 작으면 방문함
        // 양 끝에서 출발하는 경우에 해당됨
        if (map[curY][curX] + 1 >= map[ny][nx]) {
          continue;
        }
      }
      q.push({ny, nx});

      // 현재 값이 0이 아니면, 기존에 익는 일자와 새로운 일자 중 작은값으로 지정
      if (map[ny][nx] == 0) map[ny][nx] = map[curY][curX] + 1;
      else map[ny][nx] = min(map[curY][curX] + 1, map[ny][nx]);

      visited[ny][nx] = 1;
    }
  }
}

int main() {
  cin >> n >> m;
  for (int y=0; y<m; y++) {
    for (int x=0; x<n; x++) {
      cin >> map[y][x];
    }
  }

  for (int y=0; y<m; y++) {
    for (int x=0; x<n; x++) {
      if (map[y][x] > 0) {
        q.push({y, x});
        BFS();
      }
    }
  }


  for (int y=0; y<m; y++) {
    for (int x=0; x<n; x++) {
      if (map[y][x] > maxDay) maxDay = map[y][x];
      if (map[y][x] == 0) {
        cout << -1;
        return 0;
      }
    }
  }
  cout << maxDay - 1;
  return 0;
}
