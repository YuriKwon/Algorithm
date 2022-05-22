#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int n, val;
};

Node arr[8] = {};
int arr2[5] = {};

int compare(Node a, Node b) {
	if (a.val > b.val) return 1;
	else return 0;
}

int compare2(int a, int b) {
	return a < b;
}
int main() {
	for (int i=0; i<8; i++) {
		arr[i].n = i+1;
		cin >> arr[i].val;
	}
	sort(arr, arr + 8, compare);
	int sum = 0;
	for (int i=0; i<5; i++) {
		sum += arr[i].val;
		arr2[i] = arr[i].n;
	}
	sort(arr2, arr2+5, compare2);
	cout << sum << '\n';
	for (int i=0; i<5; i++) {
		cout << arr2[i] << " ";
	}
	return 0;
}
