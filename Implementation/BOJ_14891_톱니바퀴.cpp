#include <iostream>
#include <string>
#include <deque>
#include <vector>
using namespace std;

int K;
int num, dir, ans; // 회전시킨 바퀴 번호, 방향
vector < deque < char > > gears;
string gear_s;
int rotateDirection[4]; // 각 바퀴를 회전시키는 방향(-1: 반시계, 1: 시계, 0: 무회전)

int main() {
  for (int y=0; y<4; y++) {
    cin >> gear_s;
    deque<char> gear;
    for (int x=0; x<8; x++) {
      gear.push_back(gear_s[x]);
    }
    gears.push_back(gear);
  }
  cin >> K;
  for (int k=0; k<K; k++) {
    cin >> num >> dir;
    num--;
    rotateDirection[num] = dir;

    for (int i=num-1; i>=0; i--) {
      if (rotateDirection[i+1] == 0) break;
      // 맞닿는 부분
      char edge1 = gears[i][2];
      char edge2 = gears[i+1][6];
      if (edge1 != edge2) {
        // 반대방향으로 회전
        rotateDirection[i] = rotateDirection[i+1] == 1 ? -1 : 1;
      }
    }
    for (int i=num+1; i<=3; i++) {
      if (rotateDirection[i-1] == 0) break;
      // 맞닿는 부분
      char edge1 = gears[i][6];
      char edge2 = gears[i-1][2];
      if (edge1 != edge2) {
        // 반대방향으로 회전
        rotateDirection[i] = rotateDirection[i-1] == 1 ? -1 : 1;
      }
    }


    for (int i=0; i<4; i++) {
      if (rotateDirection[i] == 1) {
        // 시계방향 회전
        char back = gears[i].back();
        gears[i].pop_back();
        gears[i].push_front(back);
      } else if (rotateDirection[i] == -1) {
        // 반시계방향 회전
        char front = gears[i].front();
        gears[i].pop_front();
        gears[i].push_back(front);
      }
      rotateDirection[i] = 0;
    }
  }

  // 점수 계산
  if (gears[0][0] == '1') ans += 1;
  if (gears[1][0] == '1') ans += 2;
  if (gears[2][0] == '1') ans += 4;
  if (gears[3][0] == '1') ans += 8;
  cout << ans;
  return 0;
}
