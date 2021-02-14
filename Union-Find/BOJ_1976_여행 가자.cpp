#include <iostream>
using namespace std;

int parent[201];
int travel[1000];

//find (=find boss)
int find(int n) {
	if (parent[n] == 0) return n;
	int ret = find(parent[n]);
	parent[n] = ret;
	return ret;
}

//union (=set group)
void merge(int a, int b) {
	int bossA = find(a);
	int bossB = find(b);
	if (bossA == bossB) return;
	parent[bossB] = bossA;
}

int main() {
	int n, m;
	cin >> n >> m;

	int num;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> num;
			if (num == 1) {
				merge(y + 1, x + 1);
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		cin >> travel[i];
	}

	int flag = 0;

	for (int i = 0; i < m - 1; i++) {
		int boss1 = find(travel[i]);
		int boss2 = find(travel[i+1]);
		if (boss1 != boss2) {
			flag = 1;
			break;
		}
	}

	if (flag == 0) cout << "YES";
	else cout << "NO";

	return 0;
}