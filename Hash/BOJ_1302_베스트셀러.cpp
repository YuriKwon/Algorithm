#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
	int cnt;
	string str;
};
Node arr[1001] = {0};

int compare(Node a, Node b) {
	if (a.cnt > b.cnt) return 1;
	else if (a.cnt == b.cnt) return a.str < b.str;
	return 0;
}

int main() {
	int n;
	string s;
	int idx = 0;
	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> s;

		int flag = 0;
		for (int j=0; j<=i; j++) {
			if (arr[j].str == s) {
				arr[j].cnt++;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
            arr[idx].cnt = 1;
            arr[idx].str = s;
            idx++;
        }
	}
	sort(arr, arr+idx, compare);
	cout << arr[0].str;
	return 0;
}
