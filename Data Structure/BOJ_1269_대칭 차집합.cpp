#include <iostream>
#include <set>
using namespace std;

int num, cnt1, cnt2;
set<int> s;

int main() {
	cin >> cnt1 >> cnt2;

	for (int i=0; i<cnt1; i++) {
		cin >> num;
		s.insert(num);
	}

	for (int i=0; i<cnt2; i++) {
		cin >> num;
		if (s.find(num) == s.end()) s.insert(num);
		else s.erase(num);
	}

	cout << s.size();
	return 0;
}
