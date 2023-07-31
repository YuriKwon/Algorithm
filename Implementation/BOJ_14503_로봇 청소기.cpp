#include <iostream>
using namespace std;

int N, M, r, c, d, ans;
int arr[50][50]; // 0이면 빈칸, 1이면 벽, 청소 완료면 2
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool canClean(int y, int x) {
  for (int i=0; i<4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (arr[ny][nx] == 0) return true;
  }
  return false;
}

void init() {
  cin >> N >> M;
  cin >> r >> c >> d;

  for (int y=0; y<N; y++) {
    for (int x=0; x<M; x++) {
      cin >> arr[y][x];
    }
  }
}

int main() {
  init();

  while(true) {
    // 현재칸이 0이면, 청소
    if (arr[r][c] == 0) {
      arr[r][c] = 2;
      ans++;
    }

    // 상, 하, 좌, 우 중에 0인 칸이 있다(canClean)
    if (canClean(r, c)) {
      for (int i=0; i<4; i++) { // 앞칸이 0이아니면, 또 회전?? (이건 내가 알아서 정의해야할 듯)
        d = (d+3)%4; // -> 반시계 회전
        int ny = r + dy[d];
        int nx = c + dx[d];

        // -> 앞칸이 0이면, 전진
        if (arr[ny][nx] == 0) {
          r = ny;
          c = nx;
          break;
        }
      }
    } else {
      // 방향 유지한채 한칸 후진
      // 현재 방향의 반대: +2하면 됨
      d = (d+2)%4;
      int ny = r + dy[d];
      int nx = c + dx[d];
      d = (d+2)%4; // 방향 원상복구
      if (arr[ny][nx] == 1) break;
      r = ny;
      c = nx;
    }
  }
  cout << ans;
  return 0;
}
