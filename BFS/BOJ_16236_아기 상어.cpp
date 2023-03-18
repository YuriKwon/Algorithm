#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, num, eatCount, distanceFromShark, answer;
int arr[20][20];
int sharkSize = 2;
int sharkY, sharkX; // 상어의 위치
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
struct Node {
  int distance, y, x; // 상어~물고기까지의 거리, 물꼬기 위치
};
queue<Node> q;
int visited[20][20]; // 1이면 방문, 0이면 방문 X
bool isEatFish = false;
Node nextFish = {999999, 0, 0}; // 다음에 방문할 물고기, distance 값을 충분히 크게 줘야 함

void BFS(int sharkY, int sharkX) {
  // visited 배열 초기화
  for (int y=0; y<20; y++) {
    for (int x=0; x<20; x++) {
      visited[y][x] = 0;
    }
  }

  nextFish = {99999, 0, 0}; // 다음에 방문할 물고기 정보
  isEatFish = false;

  while(!q.empty()) {
    Node cur = q.front();
    visited[cur.y][cur.x] = 1;
    q.pop();

    for (int i=0; i<4; i++) {
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];

      // 지나갈 수 없음
      if (ny < 0 || ny >= n || nx < 0 || nx >= n || arr[ny][nx] > sharkSize) {
        continue;
      }

      // 이미 체크한 물고기
      if (visited[ny][nx]) {
        continue;
      }

      q.push({cur.distance + 1, ny, nx});
      visited[ny][nx] = 1;

      // 먹을 수 있는 물고기 & 전에 거쳤던 물고기보다 위치상 좋으면, 다음 물고기로 지정
      if (arr[ny][nx] > 0 && arr[ny][nx] < sharkSize) {
        isEatFish = true;
        visited[ny][nx] = 1;
        distanceFromShark = cur.distance + 1;

        // 다음 물고기 갱신
        if (distanceFromShark < nextFish.distance) {
          nextFish = {distanceFromShark, ny, nx};
        } else if (distanceFromShark == nextFish.distance) {
          if (ny < nextFish.y) {
            nextFish = {distanceFromShark, ny, nx};
          } else if (ny == nextFish.y && nx < nextFish.x) {
            nextFish = {distanceFromShark, ny, nx};
          }
        }
      }
    }
  }
}

int main() {
  cin >> n;

  for (int y=0; y<n; y++) {
    for (int x=0; x<n; x++) {
      cin >> num;
      arr[y][x] = num;
      if (num == 9) { // 상어 위치인 경우, 반드시 0으로 바꿔줘야 함
        sharkY = y;
        sharkX = x;
        arr[y][x] = 0;
      }
    }
  }

  // 1. 현재 지점에서 먹을 수 있는 위치 찾기(BFS) -> 없으면 break;
  while(true) {
    q.push({0, sharkY, sharkX});
    BFS(sharkY, sharkX);
    // visited 배열 초기화
    if (isEatFish) {
      sharkY = nextFish.y;
      sharkX = nextFish.x;
      answer += nextFish.distance;
      eatCount++;

      // 상어 크기 증가 조건, 문제를 꼼꼼히 보기
      if (eatCount == sharkSize) {
        sharkSize++;
        eatCount = 0;
      }

      // 먹은 위치는 0으로 변경
      arr[sharkY][sharkX] = 0;
    } else {
      cout << answer;
      break;
    }

  }
  return 0;
}


// 도움된 링크: https://www.acmicpc.net/board/view/100687
// https://www.acmicpc.net/board/view/53368
