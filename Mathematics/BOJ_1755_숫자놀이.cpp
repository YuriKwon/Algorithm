#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string num_arr[11] = {
	"zero ",
	"one ",
	"two ",
	"three ",
	"four ",
	"five ",
	"six ",
	"seven ",
	"eight ",
	"nine ",
};

struct Node {
	int n;
	string s;
};

int compare(Node a, Node b) {
	return a.s < b.s;
}

Node arr[101];
int index;

int main() {
	int a, b;
	cin >> a >> b;
	int cnt = b - a + 1;


	while (a != b+1) {
		arr[index].n = a;
		if (a < 10) {
			arr[index].s = num_arr[a];
		}
		else {
			arr[index].s = num_arr[a / 10] + num_arr[a % 10];
		}
		a++;
		index++;
	}

	int flag = 0;
	sort(arr, arr + cnt, compare);

	for (int i = 1; i <= cnt; i++) {
		cout << arr[i-1].n << " ";
		if (i != 0 && (i % 10 == 0)) cout << endl;
	}
	return 0;
}