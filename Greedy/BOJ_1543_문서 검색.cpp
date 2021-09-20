#include <iostream>
#include <string>
using namespace std;

int n, cnt, flag;
int used[2501];
string s;
string word;

int main() {

	getline(cin, s); // 한줄 입력
	getline(cin, word);
	int l = s.length();
	int len = word.length();

	for (int i = 0; i <= l-len; i++) {
		flag = 0;
		if (used[i] == 1) continue;
		for (int j = 0; j < len; j++) {
			if (s[i + j] != word[j]) {
				flag = 1;
				continue;
			}
		}
		if (flag == 1) continue;
		// 일치하면
		for (int j = 0; j < len; j++) {
			used[i + j] = 1;
		}
		cnt++;
	}

	cout << cnt;
	return 0;
}