#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<int>card(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> card[i];
	sort(card.begin(), card.end());

	cin >> m;

	vector<int>check(m, 0);
	vector<int>answer(m, 0);

	for (int i = 0; i < m; ++i) {
		cin >> check[i];
		int low = 0;
		int high = n - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (card[mid] == check[i]) {
				answer[i]++;
				break;
			}
			else if (card[mid] < check[i])
				low = mid + 1;
			else if (card[mid] > check[i])
				high = mid - 1;
		}
	}
	for (int i = 0; i < m; ++i)
		cout << answer[i] << " ";
}
