#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// 시간 제한 때문에 for문 돌려서 string 으로 더하는 방식은 안될 거라고 생각했는데, 
// 백준 게시판 보니까 그러게 해도 시간초과가 안뜬다.
int n; 
string s;
int sum;


int main() {
	cin >> s;
	int len = s.length();

	// 현재 길이 이전 값의 자리수 인 애들까지 더해주기
	for (int i = 1; i < len; i++) {
		sum += 9 * pow(10, (i - 1)) * i;
	}
	int mini = pow(10, (len - 1)); // 해당 자리수랑 같은 수 중 가장 작은 수 (252면, 100)
	n = stoi(s);
	sum += (n - mini + 1) * len;

	cout << sum;
	return 0;
}