#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int a, b;
int t;
vector<int> v;
vector<int> p;

int getGcd(long long int a, long long int b) {
	long long int r; 
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	for (int tmp, i = 0; i < t; i++) {
		cin >> tmp;
		p.push_back(tmp);

		if (i != 0) v.push_back(p[i] - p[i - 1]);
	}
	int gcd = v[0];
	for (int i = 1; i < v.size(); i++) {
		gcd = getGcd(gcd, v[i]);
	}
	int len = p[t - 1] - p[0];
	int cnt = len / gcd;
	cnt -= t - 1;

	cout << cnt;
	return 0;
}
