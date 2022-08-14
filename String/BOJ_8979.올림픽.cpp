#include <iostream>
#include <algorithm>

using namespace std;

struct country {
	int country_num;
	int gold;
	int sliver;
	int bronze;
};

bool compare(country a, country b) {
	if (a.gold > b.gold) return true;
	else if (a.gold == b.gold) {
		if (a.sliver > b.sliver) return true;
		if (a.sliver == b.sliver) {
			if (a.bronze > b.bronze) return true;
		}
	}
	return false;
}

country arr[1001];
int n, k, n1, n2, n3, n4, result, val;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> n1 >> n2 >> n3 >> n4;
		arr[i].country_num = n1;
		arr[i].gold = n2;
		arr[i].sliver = n3;
		arr[i].bronze = n4;
	}

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		if (arr[i].country_num == k) {
			result = i;
			break;
		}
	}
	for (int i = result - 1;; i--) {
		country tar = arr[result];
		country comp = arr[i];
		if (comp.gold != tar.gold || comp.sliver != tar.sliver || comp.bronze != tar.bronze) {
			break;
		}
		val++;
	}
	cout << result - val + 1 << endl;
	return 0;
}
