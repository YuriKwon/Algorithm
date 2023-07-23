// DFS나 BFS로 짜면, 중심에서 네 방향으로 뻗어나가는 ㅗ 블럭에 대한 별도 처리 필요
#include <iostream>
using namespace std;

int N, M;
int map[500][500];
int visited[500][500];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int answer;

void dfs(int y, int x, int level, int sum) {
  if (level == 4) {
    // 넓이 갱신
    answer = max(answer, sum);
    return;
  }

  for (int i=0; i<4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
    if (visited[ny][nx] == 1) continue;
    visited[ny][nx] = 1;
    dfs(ny, nx, level+1, sum + map[ny][nx]);
    visited[ny][nx] = 0;
  }

}

void checkShape(int y, int x) {
  int shapes[4][4][2] = {
    {{0, 0}, {0, 1}, {-1, 1}, {0, 2}}, // ㅗ
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}}, // ㅏ
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}}, // ㅜ
    {{0, 0}, {1, 0}, {2, 0}, {1, -1}} // ㅓ
  };

  for (int s=0; s<4; s++) { // 네개의 형태에 대해 검사
    int sum = 0;
    bool flag = true;
    for (int k=0; k<4; k++) {
      int ny = y + shapes[s][k][0];
      int nx = x + shapes[s][k][1];
      // 한 지점이라도 바깥으로 나가면, 그 형태는 불가능
      if (ny < 0 || nx < 0 || ny >= N || nx >= M) break;
      sum += map[ny][nx];
    }
    answer = max(answer, sum);
  }
}

int main() {
  cin >> N >> M;

  for (int y=0; y<N; y++) {
    for (int x=0; x<M; x++) {
      cin >> map[y][x];
    }
  }

  for (int y=0; y<N; y++) {
    for (int x=0; x<M; x++) {
      visited[y][x] = 1;
      dfs(y, x, 1, map[y][x]);
      checkShape(y, x);
      visited[y][x] = 0; // 거꾸로된 ㄱ 모양을 처리하기 위해서 필요
    }
  }
  cout << answer;
  return 0;
}
