#include <iostream>
#include <deque>
using namespace std;

deque <int> dq;
deque <int> dq2;

int del() {
	while (dq.size() != 1) {
		dq2.push_back(dq.front());
		dq.pop_front();
		dq.push_back(dq.front());
		dq.pop_front();
	}
	return dq.front();
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	int ret = del();
	int len = dq2.size();
	for (int i = 0; i < len; i++) {
		cout << dq2.front() << " ";
		dq2.pop_front();
	}
	cout << ret;
	return 0;
}