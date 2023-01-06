// 이분탐색이라기보단, lower_bound로 푸는 문제
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n;
long long minSum = 9223372036854775807;
long long minFluidVal1, minFluidVal2;
vector<long long> fluidValues; // 용액의 특성값
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> n;

  for (int i=0; i<n; i++) {
    long long val;
    cin >> val;
    fluidValues.push_back(val);
  }

  // 전부 산성, 알칼리성일 때 처리
  if (fluidValues[0] > 0) {
    cout << fluidValues[0] << " " << fluidValues[1];
    return 0;
  } else if (fluidValues[n-1] < 0) {
    cout << fluidValues[n - 2] << " " << fluidValues[n - 1];
    return 0;
  }

// 숫자의 부호를 뒤집어서 lower_bound(같거나 큰 숫자) 값의 인덱스 & 그 인덱스 -1 위치에 있는 지점을 검사
  for (int i=0; i<n; i++) {
    // lower_bound는 iterator를 반환하기 때문에, 첫번째 주소를 빼야 인덱스값을 출력할 수 있음
    int lowerBoundIdx = lower_bound(fluidValues.begin(), fluidValues.end(), -1 * fluidValues[i]) - fluidValues.begin();

    if (lowerBoundIdx <= i) continue;

    if (lowerBoundIdx < n) {
      long long tempSum = abs(fluidValues[i] + fluidValues[lowerBoundIdx]);
      if (tempSum < minSum) {
        minSum = tempSum;
        minFluidVal1 = fluidValues[i];
        minFluidVal2 = fluidValues[lowerBoundIdx];
      }
    }
    if (lowerBoundIdx - 1 != i) {
      long long tempSum = abs(fluidValues[i] + fluidValues[lowerBoundIdx - 1]);
      if (tempSum < minSum) {
        minSum = tempSum;
        minFluidVal1 = fluidValues[i];
        minFluidVal2 = fluidValues[lowerBoundIdx - 1];
      }
    }

  }

  cout << minFluidVal1 << " " << minFluidVal2;
  return 0;
}
