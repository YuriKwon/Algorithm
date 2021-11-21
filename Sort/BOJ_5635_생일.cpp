#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
	string name;
	int dd, mm, yyyy;

};
Node arr[101];

// 나이가 많은 사람부터 우선 정렬
int compare(Node a, Node b) {
	if (a.yyyy < b.yyyy) return 1;
	else if (a.yyyy > b.yyyy) return 0;
	else if (a.mm < b.mm) return 1;
	else if (a.mm > b.mm) return 0;
	else if (a.dd < b.dd) return 1;
	else return 0;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].name >> arr[i].dd >> arr[i].mm >> arr[i].yyyy;
	}
	sort(arr, arr + n, compare);
	cout << arr[n-1].name << '\n' << arr[0].name;
	return 0;
}