#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100000]; // 로프 하중을 담은 배열
int maxWeight; // 최대 하중

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<int>()); // 내림차순 정렬
	for (int i = 0; i < n; i++) {
		int weight = (i + 1) * arr[i];
		if (weight > maxWeight) maxWeight = weight;
	}
	cout << maxWeight;
	return 0;
}