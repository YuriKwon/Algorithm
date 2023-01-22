#include <iostream>
using namespace std;

int n, num, m, i, j;
int sum[100001]; // 누적합 저장 배열
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i=1; i<=n; i++) {
    cin >> num;
    sum[i] = sum[i - 1] + num;
  }

  cin >> m;
  for (int k=0; k<m; k++) {
    cin >> i >> j;
    cout << sum[j] - sum[i-1] << '\n';
  }
  return 0;
}
