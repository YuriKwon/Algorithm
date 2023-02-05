#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

string s;
int n, m;
int visited[101][101];
int arr[101][101];
struct Node {
  int y, x;
};
queue<Node> q;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS() {
  q.push({0, 0});

  while(!q.empty()) {
    int curY = q.front().y;
    int curX = q.front().x;

    // 주의: visited = 1 처리를 방문 전에 해줘야 큐에 중복으로 들어가지 않음
    // 참고: https://www.acmicpc.net/board/view/53883
    q.pop();

    for (int i=0; i<4; i++) {
      int ny = curY + dy[i];
      int nx = curX + dx[i];

      if (arr[ny][nx] == 0) {
        continue;
      } else if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
        continue;
      } else if (visited[ny][nx] == 1) {
        continue;
      }

      q.push({ny, nx});
      visited[ny][nx] = 1;
      arr[ny][nx] = arr[curY][curX] + 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m;
  for (int i=0; i<n; i++) {
    cin >> s;
    for (int j=0; j<m; j++) {
      arr[i][j] = s[j] - '0';
    }
  }

  BFS();
  cout << arr[n - 1][m - 1];

  return 0;
}
