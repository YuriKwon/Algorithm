#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int t, n, m, answer;
long long int arr1[1001];
long long int arr2[1001];
vector<long long int> subarrA; // 가능한 누적합을 저장 = 부배열의 합들을 저장
vector<long long int> subarrB;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t >> n;
  for (int i=1; i<=n; i++) {
    cin >> arr1[i];
  }
  cin >> m;
  for (int i=1; i<=m; i++) {
    cin >> arr2[i];
  }

  for (int i=1; i<=n; i++) {
    long long int sum = 0; // 누적합
    for (int j=i; j<=n; j++) {
      sum += arr1[j];
      subarrA.push_back(sum);
    }
  }

  for (int i=1; i<=m; i++) {
    long long int sum = 0; // 누적합
    for (int j=i; j<=m; j++) {
      sum += arr2[j];
      subarrB.push_back(sum);
    }
  }
  sort(subarrA.begin(), subarrA.end());
  sort(subarrB.begin(), subarrB.end());

  for (auto numA : subarrA) {
    long long int diff = t - numA;
    // 이분탐색이라 시간초과 안남
    auto ub = upper_bound(subarrB.begin(), subarrB.end(), diff);
    auto lb = lower_bound(subarrB.begin(), subarrB.end(), diff);
    answer += (ub - lb);
  }
  cout << answer;
  return 0;
}
