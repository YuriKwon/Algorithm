#include <iostream>
#include <queue>
using namespace std;

int n, m, targetY, targetX, num;
int arr[1000][1000];
int visited[1000][1000];
struct Node{
  int y, x, distance;
};
queue<Node> q;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS() {
  while(!q.empty()) {
    Node cur = q.front();
    q.pop();

    for (int i=0; i<4; i++) {
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
      if (arr[ny][nx] == 0) continue;
      if (visited[ny][nx] != 0) continue;

      visited[ny][nx] = cur.distance + 1;
      q.push({ny, nx, cur.distance + 1});
    }

  }
}

int main() {
  cin >> n >> m;
  for (int y=0; y<n; y++) {
    for (int x=0; x<m; x++) {
      cin >> num;
      if (num == 2) {
        targetY = y;
        targetX = x;
      }
      arr[y][x] = num;
    }
  }

  visited[targetY][targetX] = 1;
  q.push({targetY, targetX, 0});
  BFS();

  visited[targetY][targetX] = 0;
  for (int y=0; y<n; y++) {
    for (int x=0; x<m; x++) {
      if (visited[y][x] == 0 && arr[y][x] == 1) {
        visited[y][x] = -1;
      }
      if (arr[y][x] == 0) {
        visited[y][x] = 0;
      }
    }
  }

  for (int y=0; y<n; y++) {
    for (int x=0; x<m; x++) {
      cout << visited[y][x] << " ";
    }
    cout << "\n";
  }

}
