#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Node {
	int y, x;
};
Node queue[10000];
int head, tail;
char map[101][101];
int used[101][101];
int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};
int n;
string s;
int cnt, cnt2;

void BFS(char ch) {
	while (head != tail) {
		Node now = queue[head++];
		for (int i = 0; i < 4; i++) {
			int ny = now.y + direct[i][0];
			int nx = now.x + direct[i][1];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (map[ny][nx] != ch) continue;
			if (used[ny][nx] == 1) continue;
			queue[tail++] = { ny, nx };
			used[ny][nx] = 1;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	//일반인
	for (int y = 0; y < n; y++) {
		cin >> s;
		for (int x = 0; x < n; x++) {
			map[y][x] = s[x];
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (used[y][x] == 1) continue;
			used[y][x] = 1;
			queue[tail++] = { y,x };
			BFS(map[y][x]);
			cnt++;
		}
	}
	//적록색맹
	memset(used, 0, sizeof(used));
	head = 0;
	tail = 0;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == 'G') map[y][x] = 'R';
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (used[y][x] == 1) continue;
			used[y][x] = 1;
			queue[tail++] = { y,x };
			BFS(map[y][x]);
			cnt2++;
		}
	}
	cout << cnt << " " << cnt2;
	return 0;
}