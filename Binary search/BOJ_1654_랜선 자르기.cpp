#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, n;
long long lineLengthSum = 0;
vector<long long> lineLengthArr;
long long maxLength = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> k >> n;

  for (int i=0; i<k; i++) {
    long long lineLength;
    cin >> lineLength;
    lineLengthSum += lineLength;
    lineLengthArr.push_back(lineLength);
  }

  long long left = 1;
  long long right = lineLengthSum / n;

  while (left <= right) {
    long long middle = (left + right) / 2;
    long long totalLANCnt = 0; // 만들 수 있는 랜선의 개수
      for (int i=0; i<k; i++) {
        totalLANCnt += (lineLengthArr[i] / middle);
      }

      if (totalLANCnt >= n) {
        left = middle + 1;
        maxLength = middle;
      }
      else right = middle - 1;
  }
  cout << maxLength;

  return 0;
}
