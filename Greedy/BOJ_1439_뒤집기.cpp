#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1 <-> 0바뀌는 지점 센 후, 2로 나눈 몫
	string s;
	cin >> s;
	int len = s.length();
	int changeCnt = 0;
	for (int i = 1; i < len; i++) {
		if (s[i] != s[i - 1])changeCnt++;
	}
	if (changeCnt % 2 == 0) {
		cout << changeCnt / 2;
	}
	else {
		cout << changeCnt / 2 + 1;
	}


	return 0;
}
