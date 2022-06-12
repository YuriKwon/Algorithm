#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, num, idx1, idx2, start, endi, sum, cnt;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	cin >> x;
	sort(v.begin(), v.end());
	endi = n - 1;
	while (true) {
		if (start >= endi) break;
		sum = v[start] + v[endi];
		if (sum == x) {
			start++;
			endi--;
			cnt++;
		}
		else if (sum > x) {
			endi--;
		}
		else {
			start++;
		}
	}
	cout << cnt;

	return 0;
}
