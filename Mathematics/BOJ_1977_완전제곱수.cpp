#include <iostream>
using namespace std;

int sum;
int minNum = 10000;

int main() {
	// 1977: 완전제곱수
	int m, n;
	cin >> m >> n;

	for (int i = m; i <= n; i++) {
		// j 최대를 100으로 잡은 이유: 최대 10000이므로 100의 제곱이 최대이기 때문. 
		for (int j = 1; j <= 100; j++) {
			// 제곱수: 나머지가 0이고 + 나눈수와 몫이 같을 때.
			if (i % j != 0) continue;
			int quotient = i / j;
			if (quotient == j) {
				sum += i;
				if (i < minNum) minNum = i;
			}
		}
	}
	if (sum == 0) cout << -1;
	else cout << sum << endl << minNum;

	return 0;
}