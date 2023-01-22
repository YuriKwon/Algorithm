#include <iostream>
#define MAX 1000000000
using namespace std;

long long x, y, z;
long long answer = -1;

int main() {
  cin >> x >> y;
  long long start = 0;
  long long end = MAX; // 1. MAX인 이유

  z = (100 * y) / x;

  if (z >= 99) {
    cout << -1;
    return 0;
  }

  while(start <= end) {
    int mid = (start + end) / 2;
    int newZ = 100 * (y + mid) / (x + mid);

    if (z < newZ) { // 2. z < newZ로 비교하는 이유
      end = mid - 1;
      answer = mid;
    } else {
      start = mid + 1;
    }
  }
  cout << start;
  return 0;
}
