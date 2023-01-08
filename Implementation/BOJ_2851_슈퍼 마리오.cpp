#include <iostream>
using namespace std;

int sum; // 대신 smallerVal 쓰기.
int smallerVal, largerVal, diff1, diff2;

int main() {
  for (int i=0; i<10; i++) {
    int mush = 0;
    cin >> mush;

    int val = sum + mush;

    if (val == 100) {
      cout << 100;
      return 0;
    }

    if (val <= 100) {
      sum += mush;
      smallerVal = sum;
    } else {
      largerVal = sum + mush;
      break;
    }
  }

  if (largerVal == 0) {
    cout << smallerVal;
    return 0;
  }

  diff1 = 100 - smallerVal;
  diff2 = largerVal - 100;

  if (diff1 < diff2) cout << smallerVal;
  else cout << largerVal;

  return 0;
}
