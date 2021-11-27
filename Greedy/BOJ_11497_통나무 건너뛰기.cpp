#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int t, n, diff, max_diff;
int arr[10001]; // 입력 배열
int wood[10001]; // 나무 정렬한 배열

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		sort(arr, arr + n);
		// 배열을 오름차순으로 정렬받은 뒤, 배열이 정규분포 그래프 형태가 되도록 재구성. 
        //ex) 2, 3, 4, 5, 6 이라면 2, 4, 6, 5, 3 이 되어야 사이 간격이 최소가 됨. 
        // 처음에는 그냥 단순 정렬을 했는데, 그러면 맨앞과 맨뒤 차이가 최소가 돼서 안됨. 
		
		// 통나무 개수가 짝수일때
		if (n % 2 == 0) {
			for (int j = 0; j < (n/2); j++) {
				wood[j] = arr[j * 2];
			}
			int idx = n / 2; // 3
			for (int j = (n / 2); j < n; j++) {
				wood[j] = arr[2 * idx - 1];
				idx--;
			}
		}
        // 통나무 개수가 홀수일 때
		else {
			for (int j = 0; j <= (n / 2); j++) {
				wood[j] = arr[j * 2];
			}
			int idx = n / 2; // 3
			for (int j = (n / 2) + 1; j < n; j++) {
				wood[j] = arr[2 * idx - 1];
				idx--;
			}
		}
		max_diff = abs(wood[0] - wood[1]);
		for (int j = 0; j < n; j++) {
			if (j == (n - 1)) {
				diff = abs(wood[0] - wood[j]);
			}
			else {
				diff = abs(wood[j + 1] - wood[j]);
			}
			if (diff > max_diff) {
				max_diff = diff;
			}
		}
		cout << max_diff << '\n';
	}

	return 0;
}