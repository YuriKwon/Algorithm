#include <iostream>
using namespace std;

int r, c, t, cnt, num;
int dust[51][51];
int spread[51][51]; // 확산되는 양 별도 저장(먼지있는 칸은 확산 X이기 떄문에 필요)
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int topCleanerY, topCleanerX, bottomCleanerY, bottomCleanerX;

void input() {
  int cleanerInputCnt = 0;

  cin >> r >> c >> t;

  for (int y=0; y<r; y++) {
    for (int x=0; x<c; x++) {
      cin >> num;
      dust[y][x] = num;

      // 공기청정기 위치 저장
      if (num == -1 && cleanerInputCnt == 0) {
        topCleanerY = y;
        topCleanerX = x;
        cleanerInputCnt++;
      } else if (num == -1 && cleanerInputCnt == 1) {
        bottomCleanerY = y;
        bottomCleanerX = x;
        cleanerInputCnt++;
      }
    }
  }
}

// 미세먼지 확산
void spreadDust(int y, int x) {
  int dustAmount = dust[y][x];
  int spreadAmount = dustAmount / 5;

  // 4방향 검사
  for (int i=0; i<4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    // 벽 or 공기청정기인 경우 확산 X
    if (ny < 0 || nx < 0 || ny >= r || nx >= c || dust[ny][nx] == -1) continue;
    spread[ny][nx] += spreadAmount;
    dust[y][x] -= spreadAmount;
  }
}

// 반시계방향 순환
// 주의) 숫자 덮어쓸 땐 끝점에서 시작점 방향으로 가야함
void rotateCounterClockDirection() {
  // 위쪽 공기청정기 topCleanerY, topCleanerX
  for (int x=topCleanerX-1; x>0; x--) {
    dust[topCleanerY][x] = dust[topCleanerY][x-1];
  }

  for (int y=topCleanerY; y>0; y--) {
    dust[y][0] = dust[y-1][0];
  }

  for (int x=0; x<c-1; x++) {
    dust[0][x] = dust[0][x+1];
  }

  for (int y=0; y<topCleanerY; y++) {
    dust[y][c-1] = dust[y+1][c-1];
  }

  for (int x=c-1; x>topCleanerX; x--) {
    if (x == topCleanerX + 1) {
      dust[topCleanerY][x] = 0;
    } else {
      dust[topCleanerY][x] = dust[topCleanerY][x-1];
    }
  }

  dust[topCleanerY][topCleanerX] = -1; // 공기청정기 위치 다시 세팅
}

// 시계방향 순환
void rotateClockDirection() {
  // 아래쪽 공기청정기 bottomCleanerY, bottomCleanerX
  for (int x=bottomCleanerX-1; x>0; x--) {
    dust[bottomCleanerY][x] = dust[bottomCleanerY][x-1];
  }

  for (int y=bottomCleanerY; y<r-1; y++) {
    if (dust[y][0] != -1) {
      dust[y][0] = dust[y+1][0];
    }
  }

  for (int x=0; x<c-1; x++) {
    dust[r-1][x] = dust[r-1][x+1];
  }

  for (int y=r-1; y>bottomCleanerY; y--) {
    dust[y][c-1] = dust[y-1][c-1];
  }

  for (int x=c-1; x>bottomCleanerX; x--) {
    if (x == bottomCleanerX + 1) {
      dust[bottomCleanerY][x] = 0;
    } else {
      dust[bottomCleanerY][x] = dust[bottomCleanerY][x-1];
    }
  }

  dust[bottomCleanerY][bottomCleanerX] = -1;

}

int getSumDust() {
  int sum = 0;
  for (int y=0; y<r; y++) {
    for (int x=0; x<c; x++) {
        int currDust = dust[y][x];
        if (currDust > 0) sum += currDust;
      }
  }
  return sum;
}

int main() {
  input();

  while(cnt < t) {
    // 1. 미세먼지 확산
    for (int y=0; y<r; y++) {
      for (int x=0; x<c; x++) {
          int dustAmount = dust[y][x];
          if (dustAmount > 1) spreadDust(y, x);
        }
    }

    // 확산된 먼지 더해주기
    for (int y=0; y<r; y++) {
      for (int x=0; x<c; x++) {
        dust[y][x] += spread[y][x];
        spread[y][x] = 0; // 반드시 초기화
      }
    }
    // 2. 공기청정기 작동
    rotateCounterClockDirection(); // 위쪽 공기청정기 - 반시계방향 순환
    rotateClockDirection(); // 아래쪽 공기청정기 - 시계방향 순환
    cnt++;
  }

  cout << getSumDust();

  return 0;
}
