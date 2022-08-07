#include <iostream>
using namespace std;

int arr[31][31];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i=0; i<=n-1; i++) { // 초기화 할때 실수해서 처음에 틀림
		arr[i][0] = 1;
		arr[i][i] = 1;
	}

	for (int y=0; y<= n-1; y++) {
		for (int x=0; x<= k-1; x++) {
			if (arr[y][x] != 0) continue;
			arr[y][x] = arr[y-1][x-1] + arr[y-1][x];
		}
	}
	cout << arr[n-1][k-1];
	return 0;
}
