#include <iostream>
#include <cstring> // memcpy를 위해 필요
using namespace std;

int R, C, m;
struct Shark{
  int s, d, z;
};
Shark arr[101][101];
Shark moveArr[101][101]; // 상어 이동 후 위치 저장
// moveArr 필요한 이유: 이동 후 겹치는 위치 -> 잡아먹는 처리를 해주려면, 이동한 상어와 아직 이동X 상어 간 구분이 필요
int kingPosition = 0; // 낚시왕의 위치(열)
int answer; // 잡은 상어 크기의 합

void setNewPosition(Shark shark, int y, int x) {
  int s = shark.s;
  int d = shark.d;
  int r = y;
  int c = x;
  while(s > 0) {
    if (d == 1) {
      r -=1;
      if (r == 0) {
        d = 2;
        r = 2;
      }
    } else if (d == 2) {
      r += 1;
      if (r > R) {
        d = 1;
        r = R - 1;
      }
    } else if (d == 3) {
      c += 1;
      if (c > C) {
        d = 4;
        c = C - 1;
      }
    } else if (d == 4) {
      c -= 1;
      if (c == 0) {
        d = 3;
        c = 2;
      }
    }
    s--;
  }
  // 더 큰 애가 잡아먹는 것 처리..
  if (moveArr[r][c].z != 0) {
    if (moveArr[r][c].z < shark.z) {
      moveArr[r][c] = {shark.s, d, shark.z};
    }
  } else {
    moveArr[r][c] = {shark.s, d, shark.z};
  }
}

int main() {
  cin >> R >> C >> m;
  for (int i=0; i<m; i++) {
    int r, c, s, d, z;
    cin >> r >> c >> s >> d >> z;
    arr[r][c] = {s, d, z};
  }

  while(kingPosition < C) {
    // 1. 낚시왕 오른쪽으로 한 칸 이동
    kingPosition++;

    // 2. 낚시왕이 상어 잡음
    for (int i=1; i<=R; i++) {
      if (arr[i][kingPosition].z != 0) {
        answer += arr[i][kingPosition].z;
        arr[i][kingPosition] = {0, 0, 0};
        break;
      }
    }

    // 3. 상어 이동
    for (int y=1; y<=R; y++) {
      for (int x=1; x<=C; x++) {
        // 상어가 있으면, 이동시키기
        if (arr[y][x].z != 0) {
          setNewPosition(arr[y][x], y, x);
          // 덮어쓰기
        }
      }
    }

    // moveArr로 arr을 덮어쓰기
    memcpy(arr, moveArr, sizeof(moveArr));

    // moveArr 배열 초기화
    for (int y=1; y<=R; y++) {
      for (int x=1; x<=C; x++) {
        moveArr[y][x] = {0, 0, 0};
      }
    }
  }

  cout << answer;

  return 0;
}
