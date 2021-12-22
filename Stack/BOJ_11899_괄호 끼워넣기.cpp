#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

string s;
int len, sum, cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	len = s.length();

	for (int i = 0; i < len; i++) {
		if (s[i] == ')') {
			if (sum == 0) {
				cnt++;
			}
			else {
				sum--;
			}
		}
		else {
			// '(' 인 경우
			sum++;
		}
	}
	if (sum != 0) {
		cnt += abs(sum);
	}

	cout << cnt;
	
	return 0;
}