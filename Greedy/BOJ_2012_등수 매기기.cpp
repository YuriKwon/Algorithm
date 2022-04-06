#include <iostream>
#include <algorithm>
using namespace std;

long long n, sum; // int로 했을때 틀렸습니다. 가 떴음 -> 답이 int 범위를 넘어가는 경우 틀렸습니다가 뜬다.
int arr[500000];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		sum += abs(arr[i] - (i + 1));
	}
	cout << sum;
	return 0;
}