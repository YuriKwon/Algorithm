#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

//priority queue + BFS

struct Node {
	int y, x;
};
Node q[700];
int head, tail;
int map[30][30];
int used[30][30];
int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};
int n;
string s;
int sum; //총 단지 수
//뭔가 pq를 이상하게 쓴 느낌이..
priority_queue<int, vector<int>, greater<int>> pq;

int BFS() {
	while (head != tail) {
		Node now = q[head++];
		for (int i = 0; i < 4; i++) {
			int ny = now.y + direct[i][0];
			int nx = now.x + direct[i][1];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (map[ny][nx] == 0) continue;
			if (used[ny][nx] == 1) continue;
			q[tail++] = { ny, nx };
			used[ny][nx] = 1;
		}
	}
	return tail;
}

int main() {
	cin >> n;

	for (int y = 0; y < n; y++) {
		cin >> s;
		for (int x = 0; x < n; x++) {
			map[y][x] = (int)(s[x] - '0');
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			head = 0;
			tail = 0;
			if (used[y][x] == 1) continue;
			if (map[y][x] == 0) continue;
			used[y][x] = 1;
			q[tail++] = { y,x };
			int ret = BFS();
			pq.push(ret);
			sum++;
		}
	}
	cout << sum << '\n';
	for (int i = 0; i < sum; i++) {
		cout << pq.top() << '\n';
		pq.pop();
	}
	return 0;
}