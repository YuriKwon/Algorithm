#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v;
int sum;
int dat[500002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, num;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
		dat[num+4000]++;
		sum += num;
	}
	sort(v.begin(), v.end());

	int mean = round((float)sum / n);
	cout << mean << '\n';
	cout << v[n/2] << '\n';

	int most = -9999;
	bool not_first = false;
	int most_val = 0;

	for (int i = 0; i < 8001; i++) {
		if (dat[i] == 0) {
			continue;
		}
		if (dat[i] == most) {
			if (not_first) {
				most_val = i - 4000;
				not_first = false;
			}
		}
		if (dat[i] > most) {
			most = dat[i];
			most_val = i - 4000;
			not_first = true;
		}
	}
	cout << most_val << '\n';
	cout << v.back() - v.front() << '\n';
	return 0;
}
