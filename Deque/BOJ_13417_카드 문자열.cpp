#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, n;
	char ch;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> ch;

		deque<char> dq;
		dq.push_back(ch);

		for (int j = 0; j < n-1; j++) {
			cin >> ch;
			if (ch <= dq.front()) {
				dq.push_front(ch);
			}
			else {
				dq.push_back(ch);
			}
		}

		for (int j = 0; j < n; j++) {
			cout << dq[j];
		}
		cout << '\n';
	}
	return 0;
}
