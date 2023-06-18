// 좌표 (x, y)로 가는 경우의 수는
// (x-1, y)까지의 경우의 수 + (x, y-1)까지의 경우의 수

// BFS로 풀었다가 시간초과 -> DP로 변경, 추가학습 필요
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int H, N, answer;
long long arr[31][31];

int main() {
  ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

  cin >> H >> N;

  for(int i=0; i<31; i++) arr[0][i] = 1;

  int D = abs(H - N);
  for (int y=1; y<=D; y++) {
    arr[y][y] = arr[y-1][y];
    for (int x=y+1; x<=D; x++) {
      arr[y][x] = arr[y][x-1] + arr[y-1][x];
    }
  }

  cout << arr[D][D];
  return 0;
}
