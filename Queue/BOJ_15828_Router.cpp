#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int n, num;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	queue<int> q;

	cin >> n;
	while (true) {
		cin >> num;
		if (num == -1) break;
		if (num == 0) q.pop();
		else {
			if (q.size() < n) {
				q.push(num);
			}
			else {
				continue;
			}
		}
	}

	if (q.empty()) {
		cout << "empty";
	}
	else {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			cout << q.front() << " ";
			q.pop();
		}
	}
	return 0;
}