#include <iostream>
using namespace std;

int n, m, num;
int sum[1030][1030];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int y=1; y<=n; y++) {
    for (int x=1; x<=n; x++) {
      cin >> num;
      sum[y][x] = sum[y][x-1] + num; // 가로 방향 누적합 저장
    }
  }

  for (int i=0; i<m; i++) {
    int y1, y2, x1, x2;
    cin >> y1 >> x1 >> y2 >> x2;

    int answer = 0;
    for (int y=y1; y<=y2; y++) {
      answer += (int)(sum[y][x2] - sum[y][x1 - 1]);
    }

    cout << answer << '\n';
  }
  return 0;
}
