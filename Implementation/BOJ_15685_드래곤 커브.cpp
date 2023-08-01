#include <iostream>
#include <cmath>
#include <deque>
#include <vector>
using namespace std;

int N, x, y, d, g, ans;
int map[101][101];
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int rotate(int dir) {
  return (dir+1)%4;
}

int check(){
  for (int y=0; y<100; y++) {
    for (int x=0; x<100; x++) {
      int lt = map[y][x];
      int rt = map[y][x+1];
      int lb = map[y+1][x];
      int rb = map[y+1][x+1];
      if (lt && rt && lb && rb) ans++;
    }
  }
}

int main() {
  cin >> N;
  for (int n=0; n<N; n++) {
    // x, y: 시작점
    // d: 시작방향(0은 우, 1은 상, 2는 좌, 3은 하)
    // g: 세대
    cin >> x >> y >> d >> g;
    map[y][x] = 1;

    // 세대가 g -> 드래곤 커브의 선분수는 2^g
    int maxLineCnt = pow(2, g);
    deque<int> lineDirections; // 각 선분의 방향을 저장

    // 맨처음에 d 넣기
    lineDirections.push_back(d);

    // 라인 cnt가 maxLineCnt랑 같으면 종료
    while(lineDirections.size() != maxLineCnt) {
      // 맨 뒤에서부터 꺼내서, 회전시킨 다음에 넣기
      deque<int> nextLines;
      int lineLength = lineDirections.size();
      for (int i=lineLength-1; i>=0; i--) {
        nextLines.push_back(rotate(lineDirections[i]));
      }

      while(!nextLines.empty()) {
        lineDirections.push_back(nextLines.front());
        nextLines.pop_front();
      }

    }

    for (int i=0; i<maxLineCnt; i++) {
      int dir = lineDirections[i];
      y += dy[dir];
      x += dx[dir];

      map[y][x] = 1;
    }
  }

  check();
  cout << ans;

  return 0;
}
