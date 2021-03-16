//시간초과나서 질문함 - 3.7.일
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int target[100000];
int n, m;

int bs(int target) {
	int s = 0;
	int e = n - 1;
	int mid;
	while (1) {
		//여기 괄호 빼먹어서 계속 틀림
		mid = (s + e) / 2;
		if (target == arr[mid]) return 1;
		//등호를 넣어야 하는 이유(s=e인경우 무한루프)
		// 3 / 1 2 2 / 4 / 0 2 1 5 가 반례
		if (s >= e) return 0;
		//mid로 지정하는 경우 arr두개일 때 무한 루프
		if (target > arr[mid]) s = mid+1;
		else e = mid-1;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//이분탐색에서 정렬 코드를 빼먹지 말기
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> target[i];
	}
	for (int i = 0; i < m; i++) {
		//int ret = bs(target[i]);
		cout << bs(target[i]) << '\n';
	}
	return 0;
}