#include <iostream>
#include <algorithm>
using namespace std;
 
int t, l, r, a, b, mid;
 
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> l >> r;
		a = r;
		mid = (a / 2) + 1;
		if (l <= mid) b = mid;
		else b = l;
 
		cout << a % b << '\n';
	}
	return 0;
}
