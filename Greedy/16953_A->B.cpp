#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long long int a, b, cnt;

// 그리디 문제, 추후 다시 풀어보기
// B -> A 로 간다고 거꾸로 생각하기
int main() {
  cin >> a >> b;
  while(true) {
    if (a > b) {
			cout << -1;
			break;
		}
		if (a == b) {
			cout << cnt + 1;
			break;
		}

		if (b % 10 == 1) {
			b /= 10;
		}
		else if(b % 2 == 0){
			b /= 2;
		}
		else {
			cout << -1;
			break;
		}
		cnt++;
  }

  return 0;
}
