// 주의: 도망자끼리 위치가 겹쳐져 주어지는 경우는 없으며 라는 조건이 있었지만, 이동을 통해 위치가 같아지는 케이스가 존재함
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, H; // M: 도망자, H: 나무
struct Node {
  int y, x, d; // 방향을 기록(우, 하, 좌, 상이 1, 2, 3, 4)
};
vector<Node> runners2;
int trees[100][100];
int answer; // 술래의 총 점수
int sulraeRotateTurn;
int sulraeRotateDir; // 1이면 시계방향, -1이면 반시계 방향
int sulraeY, sulraeX, sulraeDir;
int dy[5] = {0, 0, 1, 0, -1};
int dx[5] = {0, 1, 0, -1, 0};
vector<int> changeDirPoint; // 방향이 바뀌는 지점 기록
vector<int> changeDirPoint_reverse; // 방향이 바뀌는 지점: 거꾸로일때

// 주의, dy dx가 0말고 1부터 시작해야 함
void input() {
  cin >> N >> M >> H >> K;
  for (int i=0; i<M; i++) {
    int y, x, d;
    cin >> y >> x >> d;
    runners2.push_back({y-1, x-1, d});
  }
  for (int i=0; i<H; i++) {
    int y, x;
    cin >> y >> x;
    trees[y-1][x-1] = 1;
  }

}

int getDistanceFromSulrae(int y, int x) {
  return abs(y - sulraeY) + abs(x - sulraeX);
}

void printRunner() {
  int runnerSize = runners2.size();
  for (int i=0; i<runnerSize; i++) {
    Node currentRunner = runners2[i];

    cout << currentRunner.y << " " << currentRunner.x << " " << currentRunner.d << endl;
  }
}

// 도망자 이동
void moveRunner() {
  // 술래와의 거리가 3이하인 도망자만 이동
  // 바라보고 있는 방향으로 1칸 이동
  // 격자 안: 술래가 있는 칸이면 이동 X, 술래 없는 칸이면 이동
  // 격자 밖: 방향을 반대로 틀고, 그 방향으로 1칸 이동 시에 술래가 없으면, 거기로 이동 (술래 있어도 방향은 튼다. 주의점)

  // 구현방법
  // 이중 for문으로 runner를 검사
  // runner가 > 0 이고, 술래와의 거리가 3이하면, 걔를 이동시킨다!
  // ny nx를 구해
  // 격자밖이면 방향을 틀고, 한칸 전진시켜 새로운 ny nx 세팅
  // ny nx 칸에 술래가 없으면 이동, -> 이동한 애는 newRunner 배열 값에 세팅해준다.

  // 구현방법 변경: 이중 for문 말고, 각각 순회하면서..
  int runnerSize = runners2.size();
  for (int i=0; i<runnerSize; i++) {
    Node currentRunner = runners2[i];
    int runnerDir = currentRunner.d;

      // 이미 나간 도망자
      if (runnerDir == 0) {
        continue;
      }

      int dist = getDistanceFromSulrae(currentRunner.y, currentRunner.x);

      // 도망자가 있는데 거리가 3 초과면 이동 X
      if (dist > 3) {
        continue;
      }

      // 이동
      int ny = currentRunner.y + dy[runnerDir];
      int nx = currentRunner.x + dx[runnerDir];

      int newDir = runnerDir;
      // 격자 외부인 경우
      if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
        newDir = (runnerDir + 2) % 4;
        if (newDir == 0) newDir = 4; // 예외처리
        ny = currentRunner.y + dy[newDir]; // 새로운 ny, nx
        nx = currentRunner.x + dx[newDir];
      }

      // ny, nx에 술래가 없으면, 이동
      if (ny != sulraeY || nx != sulraeX) {
        runners2[i] = {ny, nx, newDir};
      }

  }
}


void printSulrae() {
  cout << sulraeY << " " << sulraeX << " " << sulraeDir << endl;
}

void init() {
  vector<int> temp;
  for (int i=2; i<N; i++) {
    if (i == N-1) temp.push_back(N-1);
    temp.push_back(i);
    temp.push_back(i);
  }
  // temp 벡터: 2, 2, 3, 3, 4, 4, 4 -> N이 5인 경우

  // vector<int> changeDirPoint; // 방향이 바뀌는 지점 기록
  // 결과: 1, 2, 4, 6, 9, 12 등..
  changeDirPoint.push_back(0);
  changeDirPoint.push_back(1);
  changeDirPoint.push_back(2);
  int tempSize = temp.size();
  for (int i=0; i<tempSize; i++) {
    int last = changeDirPoint.back();
    changeDirPoint.push_back(last + temp[i]);
  }

  sulraeRotateTurn = 0;
  sulraeRotateDir = 1;

}

void printDirPoint() {
  int len = changeDirPoint.size();
  for (int i=0; i<len; i++) {
    cout << changeDirPoint[i] << " ";
  }
  cout << endl;
}

// 술래 이동
void moveSulrae(int currentTurn) {

  // currentTurn말고, rotateTurn을 별도로 관리하기 -> (0,0)이나 중심점 도달 시 초기화 해주는.. 방향 교체지점체크를 위한 값
  // 1, 2, 4, 6, 9... 벡터 만들기 (n-1까지 하고, 마지막꺼 하나 더 넣어주기) -> 방향 교체 지점
  // 처음 방향은 위쪽으로 하고, 현재 턴이 1, 2, 4, 6 등.. 벡터 안에 숫자면, 방향을 바꿔준다
  // 방향 바꿀 때, vector가 오름차순이면.. 시계방향.. 내림차순이면 반시계 방향.. -> 전역변수로 관리..
  // 다음칸이 (0,0)이거나, 중심점인 경우, 벡터를 뒤집어준다. reverse.. 그리고 방향도 시계<->반시계 전환해준다. (이떈 방향을 180도 틀어야함에 주의!!)
  // 위의 과정이 술래의 next 위치를 구하는 과정이고..
  // 그때 주의점은 이동 후 방향도 바로 바로 틀어지는지 확인해야 한다는 점

  // sulraeRotateTurn은 시계방향이면 1씩 증가, 반시계면 1씩 감소하도록 설계
  if (sulraeRotateDir == 1) {
    sulraeRotateTurn++;
  } else {
    sulraeRotateTurn--;
  }
  // ny, nx
  int ny = sulraeY + dy[sulraeDir];
  int nx = sulraeX + dx[sulraeDir];
  // 해당 위치로 술래를 이동, 방향도 전환
  sulraeY = ny;
  sulraeX = nx;
  int pointLen = changeDirPoint.size();
  for (int i=0; i<pointLen; i++) {
    if (sulraeRotateTurn == changeDirPoint[i]) {
      // 끝점인 경우, 방향을 다르게 처리
      if ((ny == N / 2 && nx == N / 2) || (ny == 0 && nx == 0)) {
        // 맨 끝에 도달한 경우
        sulraeRotateDir *= -1; // 회전 방향 전환
        // sulraeDir을 180도 회전한다.
        sulraeDir = (sulraeDir + 2) % 4;
        if (sulraeDir == 0) sulraeDir = 4; // 예외처리
        return;

      }
      // 방향 전환
      // 시계방향으로 회전
      if (sulraeRotateDir == 1) {
        sulraeDir = (sulraeDir + 1) % 4;
      } else {
        // 반시계
        sulraeDir = (sulraeDir - 1) % 4;

      }
      if (sulraeDir == 0) sulraeDir = 4; // 예외처리

    }
  }

}

// 도망자 잡기
void catchRunner(int turn) {
  // 이동 + 방향 전환 마쳤으면, 시야를 체크
  // 현재 칸 포함하여, 바라보는 방향으로 "3칸" 체크,
  // 도망자가 있고, 그 칸에 나무가 없으면, 도망자 잡아(없애고) + 잡은 도망자 수를 카운트
  // 잡은 도망자 수 * 현재 턴만큼 점수에 더하기
  int catchCnt = 0;
  for (int i=0; i<3; i++) {
    int ny = sulraeY + dy[sulraeDir] * i;
    int nx = sulraeX + dx[sulraeDir] * i;
    // ny, nx -> 술래가 바라보는 칸
    if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
      continue;
    }
    int runnerSize = runners2.size();
    for (int j=0; j<runnerSize; j++) {
      Node cur = runners2[j];
      if (cur.y == ny && cur.x == nx && cur.d > 0 && trees[ny][nx] == 0) {
        catchCnt++;
        runners2[j] = {ny, nx, 0};
        // 한 칸에 도망자가 여러명있을 수 있으므로, break하면 안됨
      }
    }
  }

  answer += (turn * catchCnt);
}

int main() {
  input();
  init();

  sulraeY = N / 2;
  sulraeX = N / 2;
  sulraeDir = 4; // 처음에 상(윗쪽) 바라봄
  for (int round = 1; round <= K; round++) {
    moveRunner();
    moveSulrae(round);
    catchRunner(round);


  }
  cout << answer;
  return 0;
}
