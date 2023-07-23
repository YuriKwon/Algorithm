#include <iostream>
using namespace std;

int N, M, y, x, K;
int map[20][20];
int yAxis[4] = {2, 1, 5, 6}; // 주사위의 세로방향 회전축
int xAxis[3] = {4, 1, 3}; // 주사위의 가로방향 회전축
int DAT[7]; // 주사위의 각 칸에 쓰여있는 숫자를 기록
int bottom, top, previousTop;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

void placeDice(int direction) {
  int currentMapValue = map[y][x];

  if (currentMapValue == 0) {
    map[y][x] = DAT[bottom];
  } else {
    DAT[bottom] = map[y][x];
    map[y][x] = 0;
  }

  return;
}

int main() {
  cin >> N >> M >> y >> x >> K;
  for (int n=0; n<N; n++) {
    for (int m=0; m<M; m++) {
      cin >> map[n][m];
    }
  }
  // y, x: 주사위의 현재 위치
  for (int k=0; k<K; k++) {
    int cmd;
    cin >> cmd;

    int ny = y + dy[cmd-1];
    int nx = x + dx[cmd-1];
    if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
      continue;
    }
    y = ny;
    x = nx;


    switch(cmd) {
      case 1: // 동
        // 가로 - 2, 3인덱스가 1, 2로 가고, 3위치에는 세로축의 맨뒤의 애가 옴
        // 세로 = 두번째칸이 가로의 맨 오른쪽애로 대체되고, 네번째칸이 맨 왼쪽으로 대체됨
        bottom = xAxis[2]; // 3
        top = xAxis[0]; // 4
        previousTop = yAxis[3];
        xAxis[0] = xAxis[1];
        xAxis[1] = xAxis[2];
        xAxis[2] = previousTop;
        yAxis[1] = bottom;
        yAxis[3] = top;
        break;
      case 2: // 서
        // 가로: 0, 1 이 1, 2로 가고, 0번인덱스엔 prevTop이 옴
        // 세로: 두번째칸이 가로의 맨 왼쪽, 네번째칸이 가로의 맨 오른쪽으로
        bottom = xAxis[0];
        top = xAxis[2];
        previousTop = yAxis[3];
        xAxis[2] = xAxis[1];
        xAxis[1] = xAxis[0];
        xAxis[0] = previousTop;
        yAxis[1] = bottom;
        yAxis[3] = top;
        break;
      case 3: // 북
        previousTop = yAxis[3];
        bottom = yAxis[0];
        top = yAxis[2];
        xAxis[1] = bottom;
        yAxis[2] = yAxis[1];
        yAxis[0] = previousTop;
        yAxis[1] = bottom;
        yAxis[3] = top;
        break;
      case 4: // 남
        bottom = yAxis[2];
        top = yAxis[0];
        xAxis[1] = bottom;
        yAxis[0] = yAxis[1];
        yAxis[1] = bottom;
        yAxis[2] = yAxis[3];
        yAxis[3] = top;
        break;
      default:
        break;
    }

    placeDice(cmd);
    // 이동시마다 윗면의 숫자를 출력
    cout << DAT[top] << '\n';

  }
  return 0;
}
