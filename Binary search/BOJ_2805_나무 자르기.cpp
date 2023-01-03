#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m, woodCuttingSize;
vector<long long> woods;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i=0; i<n; i++) {
    long long num;
    cin >> num;
    woods.push_back(num);
  }

  sort(woods.begin(), woods.end()); // 정렬하지 말고 위에서 max 저장?

  long long left = 0;
  long long right = woods[n - 1];

  while (left <= right) {
    long long middle = (left + right) / 2;
    long long cuttedWoodSum = 0;

    for (int i=0; i<n; i++) {
      long long cuttedSize = woods[i] - middle;
      if (cuttedSize > 0) cuttedWoodSum += cuttedSize;
    }

    if (cuttedWoodSum >= m) {
      left = middle + 1;
      woodCuttingSize = middle;
    }
    else right = middle - 1;
  }

  cout << woodCuttingSize;
  return 0;
}

// 테스트 케이스: https://www.acmicpc.net/board/view/41700
