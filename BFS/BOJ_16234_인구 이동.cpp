#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, L, R, ans;
int map[50][50];
int visited[50][50];
struct Node{
  int y, x;
};
queue<Node> q;
vector<Node> v;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool isEnd = true;
long long int sum;

void BFS() {
  while(!q.empty()) {
    Node head = q.front();
    q.pop();

    for(int i=0; i<4; i++) {
      int ny = head.y + dy[i];
      int nx = head.x + dx[i];

      if (ny < 0 || nx < 0 || ny>=N || nx>=N) continue;
      if (visited[ny][nx]) continue;

      int diff = abs(map[head.y][head.x] - map[ny][nx]);
      if (diff >= L && diff <= R) {
        q.push({ny, nx});
        visited[ny][nx] = 1;
        v.push_back({ny, nx});
        sum += map[ny][nx];
      }
    }
  }

}

void input() {
  cin >> N >> L >> R;
  for (int y=0; y<N; y++) {
    for (int x=0; x<N; x++) {
      cin >> map[y][x];
    }
  }
}

void init() {
  // 여기서 visited초기화
  for (int y=0; y<N; y++) {
    for (int x=0; x<N; x++) {
      visited[y][x] = 0;
    }
  }
}

int main() {
  input();

  while(true) {
    isEnd = true;
    init();

    // 한개의 연합을 찾는..
    for (int y=0; y<N; y++) {
      for (int x=0; x<N; x++) {
        if (visited[y][x] == 1) continue;
        v.clear();
        v.push_back({y, x});
        q.push({y, x});
        visited[y][x] = 1;

        sum = map[y][x];

        BFS();
        int len = v.size();

        if (len > 1) {
          isEnd = false;
          for (int i=0; i<len; i++) {
            map[v[i].y][v[i].x] = sum / len;
          }
        }
      }
    }

    if (isEnd) break;
    else ans++;

  }
  cout << ans;
  return 0;
}
