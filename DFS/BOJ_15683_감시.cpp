#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, num, cctvCnt;
int minHideArea = 99999; // 사각지대 크기(최소값이 answer)
int arr[9][9];
struct CCTV{
  int y, x, type;
};
vector<CCTV> v;

// 왼쪽 방향으로 색칠
void fillLeft(int y, int x) {
  for (int i=x; i>=0; i--) {
    if (arr[y][i] == 6) return; // 벽 만나면, 색칠 종료
    if (arr[y][i] == 0) arr[y][i] = -1; // 0일 때만 색칠(CCTV는 가리면 안됨)
  }
}

// 오른쪽 방향으로 색칠
void fillRight(int y, int x) {
  for (int i=x; i<m; i++) {
    if (arr[y][i] == 6) return; // 벽 만나면, 색칠 종료
    if (arr[y][i] == 0) arr[y][i] = -1; // 색칠
  }
}

void fillUp(int y, int x) {
  for (int i=y; i>=0; i--) {
    if (arr[i][x] == 6) return;
    if (arr[i][x] == 0) arr[i][x] = -1; // 색칠
  }
}

void fillDown(int y, int x) {
  for (int i=y; i<n; i++) {
    if (arr[i][x] == 6) return;
    if (arr[i][x] == 0) arr[i][x] = -1; // 색칠
  }
}

// CCTV 타입, 방향에 따라 색칠 처리
void fillByCCTV(CCTV current, int direction) {
  int y = current.y;
  int x = current.x;
  int type = current.type; // CCTV 타입(번호)

  if (type == 1) {
    switch (direction) {
      case 0:
        fillLeft(y, x);
        break;
      case 1:
        fillRight(y, x);
        break;
      case 2:
        fillUp(y, x);
        break;
      case 3:
        fillDown(y, x);
        break;
      default:
        break;
    }
  } else if (type == 2) {
    switch (direction) {
      case 0: case 1:
        fillLeft(y, x);
        fillRight(y, x);
        break;
      case 2: case 3:
        fillUp(y, x);
        fillDown(y, x);
        break;
      default:
        break;
    }
  } else if (type == 3) {
    switch (direction) {
      case 0:
        fillUp(y, x);
        fillRight(y, x);
        break;
      case 1:
        fillDown(y, x);
        fillRight(y, x);
        break;
      case 2:
        fillDown(y, x);
        fillLeft(y, x);
        break;
      case 3:
        fillUp(y, x);
        fillLeft(y, x);
        break;
      default:
        break;
    }
  } else if (type == 4) {
    switch (direction) {
      case 0:
        fillUp(y, x);
        fillRight(y, x);
        fillLeft(y, x);
        break;
      case 1:
        fillUp(y, x);
        fillDown(y, x);
        fillRight(y, x);
        break;
      case 2:
        fillDown(y, x);
        fillLeft(y, x);
        fillRight(y, x);
        break;
      case 3:
        fillUp(y, x);
        fillDown(y, x);
        fillLeft(y, x);
        break;
      default:
        break;
    }
  }
}

int countHideArea() {
  int hideAreaCnt = 0;
  for (int y=0; y<n; y++) {
    for (int x=0; x<m; x++) {
      if (arr[y][x] == 0) hideAreaCnt++;
    }
  }
  return hideAreaCnt;
}

void dfs(int level) {
  if (level == cctvCnt) {
    // 사각지대 개수 갱신
    minHideArea = min(countHideArea(), minHideArea);
    return;
  }

  CCTV current = v[level]; // y, x, type

  // vector[level]에 들어있는 CCTV를. 4방향으로 회전 & 다녀와서 백업한 상태로 배열 복원
  for (int i=0; i<4; i++) {
    // 4방향으로 각각 색칠
    int prevArr[9][9]; // 색칠 이전의 배열을 저장하기 위한 변수
    memcpy(prevArr, arr, sizeof(arr));
    fillByCCTV(current, i); // 색칠

    dfs(level + 1);
    // 여기서 arr를 색칠 이전으로 돌려놓기
    memcpy(arr, prevArr, sizeof(prevArr));
  }
}

int main() {
  cin >> n >> m;
  for (int y=0; y<n; y++) {
    for (int x=0; x<m; x++) {
      cin >> num;
      arr[y][x] = num;
       if (num >= 1 && num <= 4) {
        // CCTV 벡터에 추가
        v.push_back({y, x, num});
      }
    }
  }

  for (int y=0; y<n; y++) {
    for (int x=0; x<m; x++) {
      // 5번 CCTV는 회전이 의미 없으므로, 감시 영역 미리 -1로 색칠
      // 색칠을 위의 이중 포문에서 하면 안됨. (CCTV도 -1로 덮이는 문제 발생)
      num = arr[y][x];
      if (num == 5) {
        fillLeft(y, x);
        fillRight(y, x);
        fillUp(y, x);
        fillDown(y, x);
      }
    }
  }

  cctvCnt = v.size(); // 5번 CCTV를 제외한 CCTV 개수
  dfs(0);
  cout << minHideArea;
  return 0;
}
