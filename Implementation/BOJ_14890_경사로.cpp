#include <iostream>
#include <algorithm>
using namespace std;

int n, l, blockCnt, answer; // blockCnt: 현재 높이에서 블록이 몇개 있는지 개수
int arr[101][101];
int isSlope[101]; // 경사로가 놓여져있으면 1
bool canPass = false;

void input() {
  cin >> n >> l;
  for (int y=0; y<n; y++) {
    for (int x=0; x<n; x++) {
      cin >> arr[y][x];
    }
  }
}

void init() {
  canPass = true;
  blockCnt = 0;
  for (int i=0; i<n; i++) {
    isSlope[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  input();

  // 가로 줄 검사
  for (int y=0; y<n; y++) {
    init();

    for (int x=0; x<n-1; x++) {
      int curr = arr[y][x];
      int next = arr[y][x+1];

      if (curr == next) {
        if (!isSlope[x]) blockCnt++;
      }
      else if (curr == next - 1) { // next가 한 칸 더 높은 경우
        // 현재 위치에 경사로 설치 가능한지 체크
        if (!(blockCnt >= l-1 && !isSlope[x])) break;
        blockCnt = 0; // cnt값 초기화
      } else if (curr == next + 1) { // next가 한칸 더 낮은 경우
        blockCnt = 0;
        if (x + l > n) break; // 내리막 경사로를 놓을 수 있는지 체크
        for (int i=0; i<l; i++) {
          if (next != arr[y][x+1+i]) {
            canPass = false;
            break; // 높이가 다 같은지 체크
          }
        }
        // 경사로 체크해주기
        for (int i=0; i<l; i++) {
          isSlope[x+1+i] = 1;
        }
      } else {
        // 두칸이상 차이나는 경우
        break;
      }

      if (canPass && x == n-2) {
        answer++;
      }
    }
  }

  // 세로 줄 검사
  for (int x=0; x<n; x++) {
    init();

    for (int y=0; y<n-1; y++) {
      int curr = arr[y][x];
      int next = arr[y+1][x];

      if (curr == next) {
        if (!isSlope[y]) blockCnt++;
      }
      else if (curr == next - 1) { // next가 한 칸 더 높은 경우
        // 현재 위치에 경사로 설치 가능한지 체크
        if (!(blockCnt >= l-1 && !isSlope[y])) break;
        blockCnt = 0; // cnt값 초기화
      } else if (curr == next + 1) { // next가 한칸 더 낮은 경우
        blockCnt = 0;
        if (y + l > n) break; // 내리막 경사로를 놓을 수 있는지 체크
        for (int i=1; i<=l; i++) {
          if (next != arr[y+i][x]) {
            canPass = false;
            break; // 높이가 다 같은지 체크
          }
        }
        // 경사로 체크해주기
        for (int i=1; i<=l; i++) {
          isSlope[y+i] = 1;
        }
      } else {
        // 두칸이상 차이나는 경우
        break;
      }

      if (canPass && y == n-2) {
        answer++;
      }
    }
  }

  cout << answer;

  return 0;
}
