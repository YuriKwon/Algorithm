// DFS로만 풀면 시간초과나므로, DP 필요
// dp[a][b] = c의 의미 -> (a, b)에서는 도착점까지 c개의 경로로 도달할 수 있다.
// dp배열 -1로 초기화하는 이유: 0은 해당 좌표에서 도착점까지 갈 수 있는 경로가 0개라는 뜻이기 때문

#include <iostream>
using namespace std;

int m, n, answer;
int map[501][501];
int dp[501][501];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void input() {
  cin >> m >> n;

  for (int y=0; y<m; y++) {
    for (int x=0; x<n; x++) {
      cin >> map[y][x];
      dp[y][x] = -1; // dp 초기화
    }
  }
}

int DFS(int y, int x) {
  if (y == m - 1 && x == n - 1) { // 도착 지점
    return 1;
  }
  if (dp[y][x] != -1) return dp[y][x];

  dp[y][x] = 0;

  for (int i=0; i<4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >=m || nx >= n || map[y][x] <= map[ny][nx]) continue;

    dp[y][x] = dp[y][x] + DFS(ny, nx);
  }
  return dp[y][x];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  input();

  answer = DFS(0, 0);
  cout << answer;
  return 0;
}

// 참고: https://yabmoons.tistory.com/340
