#include <iostream>
#include <vector>
using namespace std;

int n, m, k, answer;
struct Ball {
  int y, x, m, s, d; // 좌표, 질량, 속력, 방향
};
vector<Ball> balls;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int getNewY(int y, int d, int s) {
  int ny = y + dy[d] * s;
  // 경계값 처리(양 끝이 연결됨)
  while(ny < 0) {
    ny += n;
  }
  while(ny >= n) {
    ny -= n;
  }

  return ny;
}

int getNewX(int x, int d, int s) {
  int nx = x + dx[d] * s;

  while(nx < 0) {
    nx += n;
  }
  while(nx >= n) {
    nx -= n;
  }

  return nx;
}

void moveBalls() {
  int ballCnt = balls.size(); // 볼 개수
  for (int i=0; i<ballCnt; i++) {
    Ball currentBall = balls[i];
    if (currentBall.m == 0) continue; // 질량 0인 볼은 취급 X
    int ny = getNewY(currentBall.y, currentBall.d, currentBall.s);
    int nx = getNewX(currentBall.x, currentBall.d, currentBall.s);
    balls[i] = {ny, nx, currentBall.m, currentBall.s, currentBall.d}; // 이동 처리
  }
}

void divideBall() {
  for (int y=0; y<n; y++) {
    for (int x=0; x<n; x++) {
      // (y, x)에 있는 파이어볼의 개수
      int ballCnt = balls.size(); // 전체 볼 개수

      int sameSpaceBallCnt = 0; // 현재 칸에 있는 전체 볼 개수
      int sameSpaceBallSumM = 0; // 현재 칸에 있는 볼 질량 합
      int sameSpaceBallSumS = 0; // 현재 칸에 있는 볼 속도 합
      bool allEven = true; // 현재 칸에 있는 공의 방향이 모두 짝수
      bool allOdd = true; // 현재 칸에 있는 공의 방향이 모두 홀수

      for (int i=0; i<ballCnt; i++) {
        Ball currentBall = balls[i];
        if (currentBall.m == 0) continue; // 질량 0인 볼은 취급 X

        if (currentBall.y == y && currentBall.x == x) {
          sameSpaceBallCnt++;
          sameSpaceBallSumM += currentBall.m;
          sameSpaceBallSumS += currentBall.s;
          if (currentBall.d % 2 == 0) allOdd = false;
          else allEven = false;
        }
      }

      // 같은 칸에 볼이 2개 이상이면
      if (sameSpaceBallCnt > 1) {
        int dividedBallM = sameSpaceBallSumM / 5;
        int dividedBallS = sameSpaceBallSumS / sameSpaceBallCnt;

        // 현재 볼 없애기(질량 0으로 변경)
        for (int i=0; i<ballCnt; i++) {
          Ball currentBall = balls[i];
          if (currentBall.m == 0) continue; // 질량 0인 볼은 취급 X

          if (currentBall.y == y && currentBall.x == x) {
            balls[i].m = 0;
          }
        }

        if (dividedBallM == 0) continue;

        if (allEven || allOdd) {
          // 0, 2, 4, 6
          for (int i=0; i<=6; i += 2) { // 방향
            Ball b;
            b.y = y;
            b.x = x;
            b.m = dividedBallM;
            b.d = i;
            b.s = dividedBallS;
            balls.push_back(b); // makeNewBall
          }
        } else {
          // 1, 3, 5, 7
          for (int i=1; i<=7; i += 2) { // 방향
            Ball b;
            b.y = y;
            b.x = x;
            b.m = dividedBallM;
            b.d = i;
            b.s = dividedBallS;
            balls.push_back(b); // makeNewBall
          }
        }

      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m >> k;
  for (int i=0; i<m; i++) {
    int y, x, m, d, s;
    cin >> y >> x >> m >> s >> d;
    balls.push_back({y-1, x-1, m, s, d});
  }

  // k번 이동
  for (int i=0; i<k; i++) {
    moveBalls();
    divideBall();
  }

  int ballCnt = balls.size(); // 전체 볼 개수

  for (int i=0; i<ballCnt; i++) {
    Ball currentBall = balls[i];
    if (currentBall.m == 0) continue; // 질량 0인 볼은 취급 X
    answer += currentBall.m;
  }

  cout << answer;
  return 0;
}
