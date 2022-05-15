#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int n, m, num, startN, endN, cnt;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	endN = n - 1;
	while (true) {
		if (startN >= endN) break;
		if (arr[startN] + arr[endN] > m) {
			endN--;
		}
		else if (arr[startN] + arr[endN] < m) {
			startN++;
		}
		else {
			cnt++;
			startN++;
			endN--;
		}
	}

	cout << cnt;
	return 0;
}
