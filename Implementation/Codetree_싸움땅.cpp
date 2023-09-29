#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, M, K;
priority_queue<int> map[21][21]; // 기본적으로 최대힙
int points[31];
struct Node{
  int y, x, d, s, point, gun;
};
Node players[31];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int anotherPlayerNum;

void init() {
  cin >> N >> M >> K;

  for (int y=0; y<N; y++) {
    for (int x=0; x<N; x++) {
      int num;
      cin >> num;
      map[y][x].push(num);
    }
  }

  for (int i=0; i<M; i++) {
    int y, x, d, s;
    cin >> y >> x >> d >> s;
    players[i] = {y-1, x-1, d, s, 0, 0};
  }
}

// 디버깅을 위한 함수
void printPeople() {
  for (int i=0; i<M; i++) {
    Node p = players[i];
    cout << i <<"번 사람 좌표: " << p.y << " , " << p.x;
    cout << " 방향:" << p.d << " 포인트: " << p.point << endl;
  }
}

void movePlayer(int num) {
  Node player = players[num];
  int ny = player.y + dy[player.d];
  int nx = player.x + dx[player.d];

  // 다음칸이 벽 너머면, 정반대 방향으로 이동
  if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
    players[num].d = (player.d + 2) % 4;
    ny = player.y + dy[players[num].d];
    nx = player.x + dx[players[num].d];
  }

  players[num].y = ny;
  players[num].x = nx;
}

bool checkAnotherPlayer(int cur) {
  Node player = players[cur];

  // 이동한 곳에 플레이어가 있으면, true
  bool isNextPositionPlayer = false;

  for (int i=0; i<M; i++) {
    if(i == cur) continue;
    Node anotherPlayer = players[i];
    if (anotherPlayer.y == player.y && anotherPlayer.x == player.x) {
      isNextPositionPlayer = true;
      anotherPlayerNum = i;
      break;
    }
  }
  return isNextPositionPlayer;
}

bool checkAnotherPlayer2(int cur, int ny, int nx) {
  // 이동한 곳에 플레이어가 있으면, true
  bool isNextPositionPlayer = false;

  for (int i=0; i<M; i++) {
    if(i == cur) continue;
    Node anotherPlayer = players[i];
    if (anotherPlayer.y == ny && anotherPlayer.x == nx) {
      isNextPositionPlayer = true;
      break;
    }
  }
  return isNextPositionPlayer;
}

void lose(int num) {
  Node player = players[num];

  // 총 내려놓기
  if (player.gun > 0) {
    map[player.y][player.x].push(player.gun);
    players[num].gun = 0;
  }

  // 1칸 이동(사람 있으면, 90도씩 회전)
  // + 빠뜨린것: 격자 범위 밖일때에도 오른쪽으로 90도 회전
  // 또 틀리는 이유: 위 두개가 아닐때에도, 이동하고 총 획득해야 함

  for (int d=0; d<4; d++) {
    int dir = (player.d + d) % 4;
    int nextY = player.y + dy[dir];
    int nextX = player.x + dx[dir];

    // 이동하려는 칸에 다른 플레이어가 있는지 확인
    // nextY가 아닌 playerY 기준이 아닌 nextY로 검사해야함
    bool isInNextPlayer = checkAnotherPlayer2(num, nextY, nextX);
    bool isOut = nextY < 0 || nextY >= N || nextX < 0 || nextX >= N;

    // 다음칸에 사람 없고, 격자내부면, 거기로 이동 후 총줍기
    if (!isInNextPlayer && !isOut) {
      players[num].y = nextY;
      players[num].x = nextX;
      players[num].d = dir;

      if (map[nextY][nextX].size() > 0) {
        players[num].gun = map[nextY][nextX].top();
        map[nextY][nextX].pop();
      }
      break;
    }
  }
}

void win(int num, int point) {
  Node player = players[num];

  // 이긴 애는 총 다시 고르기 + 포인트 획득
  if (map[player.y][player.x].size() > 0) {
    if (player.gun < map[player.y][player.x].top()) {
      if (player.gun > 0) {
        map[player.y][player.x].push(player.gun);
      }

      players[num].gun = map[player.y][player.x].top();
      map[player.y][player.x].pop();
    }
  }
  players[num].point += point;
}

void fight(int num1, int num2) {
  Node player1 = players[num1];
  Node player2 = players[num2];

  int val1 = player1.s + player1.gun;
  int val2 = player2.s + player2.gun;
  int point = abs(val1 - val2);

  // 1번이 진 경우
  if (val1 < val2 || (val1 == val2 && player1.s < player2.s)) {
    lose(num1);
    win(num2, point);
  } else {
    // 2번이 진 경우
    lose(num2);
    win(num1, point);
  }

}

int main() {
  init();
  for (int round=1; round<=K; round++) {
    for (int p=0; p<M; p++) { // player 0 ~ m-1
      movePlayer(p);
      Node player = players[p]; // 주의: move 후 선언해야함
      bool isAnotherPlayer = checkAnotherPlayer(p);

      // 이동한 곳에 플레이어가 없고, 총이 있는 경우
      if (!isAnotherPlayer && map[player.y][player.x].size() > 0) {
        // 현재 플레이어가 총을 갖고있지 않으면, 총 줍기
        if (player.gun == 0) {
          players[p].gun = map[player.y][player.x].top();
          map[player.y][player.x].pop();
        } else {
          // 현재 플레이어가 이미 총을 갖고있었던 경우, 더 큰애 갖기
          // 땅에서 새로 주우면, 기존 총을 격자에 내려놓기
          if (player.gun < map[player.y][player.x].top()) {
            map[player.y][player.x].push(player.gun);
            players[p].gun = map[player.y][player.x].top();
            map[player.y][player.x].pop();
          }
        }
      }

      // 이동한 곳에 플레이어가 있는 경우
      if (isAnotherPlayer) {
        fight(p, anotherPlayerNum);
      }
    }

  }

  for (int i=0; i<M; i++) {
    cout << players[i].point << " ";
  }
  return 0;
}
