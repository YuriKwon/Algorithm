#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int a, b;
int t;

int gcd(long long int a, long long int b) {
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
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << (a * b) / gcd(a, b) << '\n';
	}

	return 0;
}
