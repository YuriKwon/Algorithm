#include <iostream>
#include <string>
using namespace std;

string s;
string result;

int main() {
	getline(cin, s); // 한 줄 입력받기
	int len = s.length();

	for (int i = 0; i < len; i++) {
		if (s[i] == 'U' && result.empty()) {
			result += 'U';
		} else if (s[i] == 'C' && result == "U") {
			result += 'C';
		} else if (s[i] == 'P' && result == "UC") {
			result += 'P';
		} else if (s[i] == 'C' && result == "UCP") {
			result += 'C';
		}
	}

	if (result == "UCPC") {
		cout << "I love UCPC";
	} else {
		cout << "I hate UCPC";
	}
	return 0;
}
