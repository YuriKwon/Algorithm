#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string a, b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;
	int len_a = a.length();
	int len_b = b.length();
	// 최소값: 6 -> 5로
	// 최대값: 5 -> 6으로

	// 헤맨 이유: 숫자 비교시 string 으로 해야 하는데 == 6 으로 해서, if 문을 안탔다.
	for (int i = 0; i < len_a; i++) {
		if (a[i] == '6') a[i] = '5';
	}
	int min_a = stoi(a);

	for (int i = 0; i < len_a; i++) {
		if (a[i] == '5') a[i] = '6';
	}
	int max_a = stoi(a);

	for (int i = 0; i < len_b; i++) {
		if (b[i] == '6') b[i] = '5';
	}
	int min_b = stoi(b);

	for (int i = 0; i < len_b; i++) {
		if (b[i] == '5') b[i] = '6';
		// 위 방법이 안돼서 찾아본 방법.. b.replace(b.find("5"), 1, "6");
	}
	int max_b = stoi(b);

	cout << min_a + min_b << " " << max_a + max_b;

	return 0;
}