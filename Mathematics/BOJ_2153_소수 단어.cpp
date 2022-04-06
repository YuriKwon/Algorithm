#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

string s;
long long int sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	int len = s.length();
	
	for (int i = 0; i < len; i++) {
        // 여기서 소문자/대문자 분기를 해줬어야 했는데, 나는 일괄적으로 -'a'만 해줘서 계속 틀림. 
        // 아스키코드상 대문자가 소문자보다 먼저라는 걸 기억하자. 
		if ('a' <= s[i] && s[i] <= 'z') sum += (int)(s[i] - 'a' + 1);
		else sum += (int)(s[i] - 'A' + 27);
	}
	
	int flag = 0; // 소수
	for (int i = 2; i < sum; i++) {
		if (sum % i == 0) {
			flag = 1; // 소수가 아님
			break;
		}
	}

	if (flag == 0) cout << "It is a prime word.";
	else cout << "It is not a prime word.";

	return 0;
}