#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int N, K, L, X;
char C;
int map[101][101]; // 1이면 사과, 2면 뱀
struct Node{
  int x;
  char c;
};
struct Pos{
  int y, x;
};
queue<Node> moveInfo;
// 0: 상, 1: 하, 2: 좌, 3: 우
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void init() {
  cin >> N >> K;
  for (int i=0; i<K; i++) {
    int y, x;
    cin >> y >> x;
    map[y][x] = 1;
  }
  cin >> L;
  for (int i=0; i<L; i++) {
    cin >> X >> C;
    moveInfo.push({X, C});
  }
}

int main() {
  init();
  int time = 0;
  // 처음 방향: 오른쪽(0으로 나눈 나머지 3)

  deque<Pos> snake;
  snake.push_back({1, 1});
  Pos head = snake.front();
  map[head.y][head.x] = 2;
  int dir = 0;


  while(true) {
    head = snake.front();
    dir %= 4;
    int ny = head.y + dy[dir];
    int nx = head.x + dx[dir];

    // 벽에 닿은 경우
    if (ny == 0 || ny > N || nx == 0 || nx > N) break;
    // 자기 자신에 닿은 경우
    if (map[ny][nx] == 2) break;
    // 사과가 아닌 일반 칸
    if (map[ny][nx] == 0) {
      // 꼬리도 한칸 움직임
      Pos tail = snake.back();
      map[tail.y][tail.x] = 0;
      snake.pop_back();
    }
    map[ny][nx] = 2;
    snake.push_front({ny, nx});
    time++;

    // 방향 전환
    Node nextMove = moveInfo.front();
    if (nextMove.x == time) {
      char nextDir = nextMove.c;
      if (nextDir == 'L') {
        // 왼쪽으로 90도 회전: +3
        dir += 3;
      } else {
        // 오른쪽으로 90도 회전: +1;
        dir += 1;
      }
      moveInfo.pop();
      nextMove = moveInfo.front();
    }

  }
  cout << time+1;

  return 0;
}
