#include <iostream>
#include <deque>
using namespace std;

int N, M, x;
deque<int> que;
bool arr[100000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (arr[i]) continue;
		que.push_back(x);
	}
	cin >> M;
	while (M--) {
		cin >> x;
		que.push_front(x);
		cout << que.back() << ' ';
		que.pop_back();
	}
}
