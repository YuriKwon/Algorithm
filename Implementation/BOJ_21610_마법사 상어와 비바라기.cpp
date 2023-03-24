#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, answer; // n: 칸 크기, m: 이동 횟수
int d[100]; // 방향
int s[100]; // 이동 칸 수
int cloud[51][51]; // 구름 위치(구름이 있으면 1)
int newCloud[51][51]; // 새로운 구름 위치
int beforeCloud[51][51]; // 이전에 구름이 있었지만, 구름이 사라진 곳 1로 저장
int water[51][51]; // 물의 양
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1}; // 8 방향
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int diagonalY[4] = {-1, -1, 1, 1}; // 대각선 방향
int diagonalX[4] = {-1, 1, -1, 1};
struct plusWaterAmount{
  int y, x, amount; // 물복사버그 마법 단계에서 증가시킬 물의 양
};
vector<plusWaterAmount> v;

void initCloud() {
  cloud[n-1][0] = 1;
  cloud[n-1][1] = 1;
  cloud[n-2][0] = 1;
  cloud[n-2][1] = 1;
}

void inputWater() {
  for (int y=0; y<n; y++) {
    for (int x=0; x<n; x++) {
      cin >> water[y][x];
    }
  }
}

// 구름 이동
void moveCloud(int d, int s) { // d: 방향, s: 이동수
  // 이동시키고, 기존 위치는 cloud[y][x] = 0 으로 변경

  // 같은 배열에 처리하기에는, 왼쪽일 때 오른쪽일때 다 처리 방향이 달라서 복잡 -> 새로운 배열 하나 필요
  for (int y=0; y<n; y++) {
    for (int x=0; x<n; x++) {
      if (cloud[y][x] == 1) {
        int ny = y + s * dy[d];
        int nx = x + s * dx[d];

        // ny, nx가 경계를 벗어나는 값인 경우 처리하기, 여러번 반복적으로 벗어날 수 있으므로 while문
        if (ny < 0) {
          while(ny < 0) {
            ny += n;
          }
        }
        if (ny >= n) {
          while(ny >= n) {
            ny -= n;
          }
        }
        if (nx < 0) {
          while(nx < 0) {
            nx += n;
          }
        }
        if (nx >= n) {
          while(nx >= n) {
            nx -= n;
          }
        }

        newCloud[ny][nx] = 1;
      }
    }
  }
  memcpy(cloud, newCloud, sizeof(newCloud));

  // 다음 이동을 위해 초기화
  for (int y=0; y<n; y++) {
    for (int x=0; x<n; x++) {
      newCloud[y][x] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m;
  inputWater();

  // 초기 구름 위치 세팅
  initCloud();

  for (int i=0; i<m; i++) {
    int tempD, tempS;
    cin >> tempD >> s[i];
    d[i] = tempD - 1;
  }

  // M번의 이동
  for (int i=0; i<m; i++) {
    // 1. 구름 이동시키기
    moveCloud(d[i], s[i]);

    // 2. 구름 있는 곳에 물의 양 1 증가.
    for (int y=0; y<n; y++) {
      for (int x=0; x<n; x++) {
        if (cloud[y][x] == 1) {
          water[y][x]++;
        }
      }
    }

    // 3. 구름 모두 삭제(cloud 초기화). beforeCloud에 저장
    memcpy(beforeCloud, cloud, sizeof(cloud));
    for (int y=0; y<n; y++) {
      for (int x=0; x<n; x++) {
        cloud[y][x] = 0;
      }
    }

    // 4.beforeCloud에 체크된 칸 - 대각선 방향 체크(물 들어있는 칸 개수)
    // 단계별로 체크 + 물 증가하면 같은 단계 내에서 영향을 받으므로 증가할 양을 별도로 담아놓고 한번에 증가시키기
    for (int y=0; y<n; y++) {
      for (int x=0; x<n; x++) {
        int bucketCnt = 0; // 해당 위치의 대각선 중, 물이 들어있는 바구니 수

        if (beforeCloud[y][x] > 0) {
          // 대각선 4방향 전부 체크 후, 물이 0보다 크면 bucketCnt++,
          for (int j=0; j<4; j++) {
            int ny = y + diagonalY[j];
            int nx = x + diagonalX[j];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (water[ny][nx] > 0) bucketCnt++;
          }
          if (bucketCnt > 0) v.push_back({y, x, bucketCnt});
        }
      }
    }

    for (int j=0; j<v.size(); j++) {
      plusWaterAmount cur = v[j];
      water[cur.y][cur.x] += cur.amount;
    }

    v.clear();

    // 5.물의 양이 2 이상인 칸에 구름 생성 + 물의 양 2 감소 (beforeCloud 체크 안된 칸)
    for (int y=0; y<n; y++) {
      for (int x=0; x<n; x++) {
        if (beforeCloud[y][x] == 0 && water[y][x] >= 2) {
          water[y][x] -= 2;
          cloud[y][x] = 1;
        }
      }
    }

    // beforeCloud 초기화
    for (int y=0; y<n; y++) {
      for (int x=0; x<n; x++) {
        beforeCloud[y][x] = 0;
      }
    }
  }

  for (int y=0; y<n; y++) {
    for (int x=0; x<n; x++) {
      answer += water[y][x];
    }
  }

  cout << answer;

  return 0;
}
