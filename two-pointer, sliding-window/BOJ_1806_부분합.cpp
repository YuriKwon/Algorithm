#include <iostream>
using namespace std;

//10만이 넘어가는 배열은 전역배열로 선언
int arr[100000];

int main() {

	// 문제에서 주어진 n조건에 따라, min은 100,000-10을 넘을 수 없음
	int min = 1000000000;
	int start = 0;
	int end = 0;

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ret = arr[start];
	while (1) {
		//우선처리
		if (ret >= s) {
			int dif = end - start;
			if (min > dif) min = dif;
		}
		if (start == n - 1 && end == n - 1) break;

		if (end == n - 1) {
			ret -= arr[start];
			start++;
			//continue해주는 이유 : 밑의 코드 동작시 end++이 작동할 수 있기 때문
			continue;
		}
		if (ret < s) {
			end++;
			ret += arr[end];
		}
		else if (ret >= s) {
			ret -= arr[start];
			start++;
		}
	}
	// 한번 틀린이유 : 불가능일 경우 0을 출력하라는 조건을 못봤음...
	if (min == 1000000000) cout << 0;
	//+1해주는 이유 : 내가 구한 min값은 숫자 사이 간격이라서
	else cout << min+1;

	return 0;
}