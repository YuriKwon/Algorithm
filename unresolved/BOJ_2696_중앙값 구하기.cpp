#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int print() {
	int len = pq.size();
	for (int i = 0; i < len/2; i++) {
		pq.pop();
	}
	cout << pq.top();
	return pq.top();
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			pq.push(num);
			if (j % 2 == 1) {
				print();
			}
		}
	}
	return 0;
}