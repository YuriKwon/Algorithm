#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, num;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n + m; i++) {
		cout << v[i] << " ";
	}
	return 0;
}