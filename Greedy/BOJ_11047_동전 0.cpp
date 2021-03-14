#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//내림차순
	sort(arr, arr + n, greater<int>());

	//동전 개수
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cnt += k / arr[i];
		k %= arr[i];
	}
	cout << cnt;
	return 0;
}