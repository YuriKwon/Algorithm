/* 한 사람이 돈을 인출할때,
	그 사람이 인출하는데 걸리는 시간+ 다른사람들이 대기하는 시간의 총합을 구하는 문제
	-> 인출 시간이 짧은 사람이 앞 순서로 가야 한다(min 정렬)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];


int main() {
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int sum = 0;
	int num = n; //남은 대기 사람 수 + 1

	for (int i = 0; i < n; i++) {
		sum += arr[i] * num;
		num--;
	}

	cout << sum;

	return 0;
}
