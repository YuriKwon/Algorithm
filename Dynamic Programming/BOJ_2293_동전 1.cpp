#include <iostream>
using namespace std;

int n, k;
int dp[100001];
int arr[101]; // n 저장

int main() {
  cin >> n >> k;
  for (int i=0; i<n; i++) {
    cin >> arr[i];
  }

  for (int i=0; i<n; i++) {
    dp[arr[i]]++;
    for (int j = arr[i]; j<=k; j++) { // 1, 2, 5 차례대로 카운트
      dp[j] += dp[j - arr[i]];
    }
  }

  cout << dp[k];
  return 0;
}

// 학습 시 참고: https://danidani-de.tistory.com/5
