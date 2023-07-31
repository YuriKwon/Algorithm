#include <iostream>
#include <cstring>
using namespace std;

int N, M, H, a, b;
int arr[31][11];
int backupArr[31][11];
const int MAX_ANX = 4;
int ans = MAX_ANX;

// line번 세로선의 결과가 line번이 나오는 경우 true 반환
bool isSuccess(int line) {
  // 현재칸을 기준으로, 우측 이동시 +1, 좌측 이동시 -1
  int moveSpace = 0;
  int n = line;
  for (int y=1; y<=H; y++) {
    if (n==1) {
    // 맨 왼쪽 칸인 경우
      if (arr[y][n] == 1) n++;
    } else if (n==N) {
      // 맨 오른쪽 칸인 경우
      if (arr[y][n-1] == 1) n--;
    } else {
      // 그 외의 (중간) 칸인 경우
      if (arr[y][n] == 1) n++;
      else if (arr[y][n-1] == 1) n--;
    }
  }

  if (line == n) return true;
  return false;
}

void init() {
  cin >> N >> M >> H;

  for (int i=0; i<M; i++) {
    cin >> a >> b;
    arr[a][b] = 1; // 선 표시
  }
}

// 모든 세로선이 자기 자신으로 연결되는경우 true 반환
bool check() {
  for (int i=1; i<=N; i++) {
    if (!isSuccess(i)) return false;
  }
  return true;
}

void placeLadder(int level, int maxLevel) {
  if (level == maxLevel) {
    if (check()) {
      cout << level;
      exit(0);
    }
    return;
  }

  for (int x=1; x<=N; x++) {
    for (int y=1; y<=H; y++) {
      if (x==1 && arr[y][x] == 1) {
        // 맨 왼쪽 칸인 경우
        continue;
      } else if (x==N && arr[y][x-1] == 1) {
        // 맨 오른쪽 칸인 경우
        continue;
      } else {
        // 그 외의 (중간) 칸인 경우
        if (arr[y][x] == 1 || arr[y][x-1] == 1) continue;
      }
      arr[y][x] = 1;
      placeLadder(level+1, maxLevel);
      arr[y][x] = 0;

      // 제일 중요한 부분!!
      // 가지치기 - 좌, 우측에 사다리가 없으면, 1행에 놓든 2행에 놓든 사다리탄 결과가 똑같기 때문에 건너뛰는 것
      while(true) {
        if (arr[y][x-1] || arr[y][x] || arr[y][x+1]) break;
        y++;
      }
    }
  }
}

int main() {
  init();
  
  for (int l=0; l<=3; l++) {
      placeLadder(0, l);
  }

  cout << -1;
  return 0;
}
