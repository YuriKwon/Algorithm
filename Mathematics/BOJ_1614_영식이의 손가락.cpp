#include <iostream>
using namespace std;

long long int hurtFinger, maxCnt;

// 10억 -> 직접 계산이 아니라.. 문제의 의도가 수식(패턴)찾으라는 것임
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> hurtFinger >> maxCnt;

  long long int cnt = 0;
  
  if (hurtFinger == 1) {
    cnt = 8 * maxCnt;
  } else if (hurtFinger == 2) {
    if (maxCnt % 2 == 0) cnt = 1 + (8 * maxCnt/2);
    else cnt = (8 * (maxCnt/2 + 1)) - 1;
  }
  else if (hurtFinger == 3) {
    cnt = 2 + maxCnt * 4;
  }
  else if (hurtFinger == 4) {
    if (maxCnt % 2 == 0) cnt = 3 + (8 * maxCnt/2);
    else cnt = (8 * (maxCnt/2 + 1)) - 3;
  }
  else if (hurtFinger == 5) {
    cnt = 4 + maxCnt * 8;
  }

  cout << cnt;
  return 0;
}
