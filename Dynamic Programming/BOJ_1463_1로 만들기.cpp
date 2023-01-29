#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1000001];

int main() {
  cin >> n;

  dp[2] = 1;
  dp[3] = 1;

  for (int i=4; i<=n; i++) {
    if (i % 2 == 0 && i % 3 == 0) {
      dp[i] = min(1 + dp[i/2], 1 + dp[i/3]);
    } else if (i % 2 == 0) {
      dp[i] = min(1 + dp[i/2], 1 + dp[i-1]);
    } else if (i % 3 == 0) {
      dp[i] = min(1 + dp[i/3], 1 + dp[i-1]);
    } else {
      dp[i] = 1 + dp[i-1];
    }
  }
  cout << dp[n];
  return 0;
}

// 공부할 때 참고한 블로그
// https://ssinee.tistory.com/m/entry/%EB%B0%B1%EC%A4%80-1463%EB%B2%88-1%EB%A1%9C-%EB%A7%8C%EB%93%A4%EA%B8%B0-CDP
