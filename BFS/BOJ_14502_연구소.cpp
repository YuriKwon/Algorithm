#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, answer;
int arr[8][8];
int backup[8][8];
int visited[8][8];
struct Node {
  int y, x;
};
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
vector<Node> blank; // 벽을 세울 수 있는 곳들, 빈칸
vector<Node> selectedWall; // 벽을 세울 수 있는 곳들, 빈칸
queue<Node> q;

void initVisited() {
  for (int y=0; y<n; y++) {
    for (int x=0; x<m; x++) {
      visited[y][x] = 0;
    }
  }
}

void floodVirus() {
  // 바이러스 퍼뜨리기
  initVisited();
  for (int y=0; y<n; y++) {
    for (int x=0; x<m; x++) {
      if (arr[y][x] == 2 && visited[y][x] == 0) {
        q.push({y, x});

        while(!q.empty()) {
          Node cur = q.front();
          q.pop();

          for (int i=0; i<4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx] == 1) continue;
            if (arr[ny][nx] != 0) continue;
            q.push({ny, nx});
            visited[ny][nx] = 1;
            arr[ny][nx] = 2;
          }
        }
      }
    }
  }
}

void combination(int depth, int next) { // n:blank.size(), r: 3
  if (depth == 3) {
    // 선택된 3개의 벽을 칠하기
    for (int i=0; i<3; i++) {
      arr[selectedWall[i].y][selectedWall[i].x] = 1;
    }

    // 바이러스 퍼뜨리기
    floodVirus();
    // 안전영역 개수 세기
    int safeZoneCnt = 0;
    for (int y=0; y<n; y++) {
      for (int x=0; x<m; x++) {
        if (arr[y][x] == 0) {
          safeZoneCnt++;
        }
      }
    }
    // answer 갱신
    answer = max(answer, safeZoneCnt);
    // 배열 복원
    memcpy(arr, backup, sizeof(backup));

    return;
  }
  int blankCnt = blank.size();
  for (int i=next; i<blankCnt; i++) {
    selectedWall[depth] = {blank[i].y, blank[i].x};
    combination(depth+1, i+1);
  }
}

void makeWall() {
  memcpy(backup, arr, sizeof(arr));
  for (int y=0; y<n; y++) {
    for (int x=0; x<m; x++) {
      if (arr[y][x] == 0) {
        blank.push_back({y, x});
      }
    }
  }

  combination(0, 0);
}

int main() {
  cin >> n >> m;
  for (int y=0; y<n; y++) {
    for (int x=0; x<m; x++) {
      cin >> arr[y][x];
    }
  }

  for (int i=0; i<3; i++) {
    selectedWall.push_back({-1, -1});
  }

  // 아무데나 3개 벽 세우고, 그 때의 안전영역 구하기
  // 벽 결정: 모든 0 중 세 군데를 선택해야함(조합 개념 -> DFS)
  makeWall();

  cout << answer;
  return 0;
}
