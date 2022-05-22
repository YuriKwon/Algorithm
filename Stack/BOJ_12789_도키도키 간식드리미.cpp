#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue<int> st1;
stack<int> st2;
int n, num, size1, size2;

int main() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> num;
		st1.push(num);
	}

	int flag = 0;
	int next = 1;
	while(true) {
		size1 = st1.size();
		size2 = st2.size();
		if (size1 == 0 && size2 == 0) {
			break;
		} else if (size1 == 0 && size2 != 0 && st2.top() != next) {
			flag = 1; // sad
			break;
		}

		if (st1.front() == next) {
			st1.pop();
			next++;
		} else if (st2.size() != 0 && st2.top() == next) {
			st2.pop();
			next++;
		} else {
			st2.push(st1.front());
			st1.pop();
		}
	}
	if (flag == 0) cout << "Nice";
	else cout << "Sad";
	return 0;
}
