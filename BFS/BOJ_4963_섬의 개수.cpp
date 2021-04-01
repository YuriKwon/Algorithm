#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//priority queue + BFS

struct Node {
	int y, x;
};
Node q[2500];
int head, tail;
int map[50][50];
int used[50][50];
int direct[8][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1,
	-1,-1,
	-1,1,
	1,-1,
	1,1
};
string s;
int m, n;


void BFS() {
	while (head != tail) {
		Node now = q[head++];
		for (int i = 0; i < 8; i++) {
			int ny = now.y + direct[i][0];
			int nx = now.x + direct[i][1];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
			if (map[ny][nx] == 0) continue;
			if (used[ny][nx] == 1) continue;
			q[tail++] = { ny, nx };
			used[ny][nx] = 1;
		}
	}
	return;
}

int main() {
	while (1) {
		memset(used, 0, sizeof(used));
		memset(map, 0, sizeof(map));
		int sum = 0;
		cin >> n >> m;
		if (m == 0 && n == 0) break;
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) {
				cin >> map[y][x];
			}
		}
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) {
				head = 0;
				tail = 0;
				if (used[y][x] == 1) continue;
				if (map[y][x] == 0) continue;
				used[y][x] = 1;
				q[tail++] = { y,x };
				BFS();
				sum++;
			}
		}
		cout << sum << '\n';
	}

	return 0;
}