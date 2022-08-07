#include <iostream>
using namespace std;

int arr[31][31];
int sum = 0;

int main() {
	int r, c, w;
	cin >> r >> c >> w;
	int n, k;
	cin >> n >> k;

	for (int i=0; i<=r+w-1; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
	}

	for (int y=0; y<= r+w-1; y++) {
		for (int x=0; x<= y; x++) {
			if (arr[y][x] != 0) continue;
			arr[y][x] = arr[y-1][x-1] + arr[y-1][x];
		}
	}

	int idx = 0;
	for (int y=r-1; y < r+w-1; y++) {
		for (int x=0; x <= idx; x++) {
			sum += arr[y][c + x -1];
		}
		idx++;
	}
	cout << sum;
	return 0;
}
