// DFS - 백트래킹 문제
#include<iostream>
#include<algorithm>
using namespace std;

int r, c, answer;
char map[20][20];
int visited[200];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

// level -> 알파벳 개수 세기 위해 필요
void dfs(int y, int x, int level) {
  answer = max(answer, level);
  for (int i=0; i<4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny >= 0 && nx >= 0 && ny < r && nx < c) {
      char nextVal = map[ny][nx];
      if (visited[nextVal] != 1) {
        visited[nextVal] = 1;
        dfs(ny, nx, level + 1);
        visited[nextVal] = 0;
      }
    }
  }
}

int main() {
  // input
	cin >> r >> c;
	for(int y = 0; y < r; y++) {
    for (int x=0; x<c; x++) {
      cin >> map[y][x];
    }
	}

  visited[map[0][0]] = 1;
  dfs(0, 0, 1);

  cout << answer;
	return 0;
}
