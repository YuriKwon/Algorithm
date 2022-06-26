#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int b, c, d, num, sum, sum_before;
vector<int> v_b, v_c, v_d;

int getMin(int n1, int n2, int n3) {
	if (n1 <= n2 && n1 <= n3) return n1;
	else if (n2 <= n3 && n2 <= n1) return n2;
	else return n3;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> b >> c >> d;
	for (int i = 0; i < b; i++) {
		cin >> num;
		sum_before += num;
		v_b.push_back(num);
	}
	sort(v_b.begin(), v_b.end());

	for (int i = 0; i < c; i++) {
		cin >> num;
		sum_before += num;
		v_c.push_back(num);
	}
	sort(v_c.begin(), v_c.end());

	for (int i = 0; i < d; i++) {
		cin >> num;
		sum_before += num;
		v_d.push_back(num);
	}
	sort(v_d.begin(), v_d.end());

	int min_val = getMin(b, c, d);

	for (int i = 0; i < b; i++) {
		if (b - i <= min_val) {
			sum += v_b[i] * 0.9;
		}
		else {
			sum += v_b[i];
		}
	}
	for (int i = 0; i < c; i++) {
		if (c - i <= min_val) {
			sum += v_c[i] * 0.9;
		}
		else {
			sum += v_c[i];
		}
	}
	for (int i = 0; i < d; i++) {
		if (d - i <= min_val) {
			sum += v_d[i] * 0.9;
		}
		else {
			sum += v_d[i];
		}
	}
	cout << sum_before << '\n' << sum;
	return 0;
}