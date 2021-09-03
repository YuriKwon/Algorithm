#include <iostream>
#include <algorithm>
using namespace std;

int t, num, c1, c2, c3, mod3;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> num;
		c3 = num / 3;
		c1 = c3;
		c2 = c3;
		mod3 = num % 3;
		if (mod3 == 1) c1++;
		else if (mod3 == 2) c2++;
		cout << c1 << " " << c2 << '\n';
	}

	return 0;
}