#include <iostream>
#include <utility> //for using pair
#include <vector>
using namespace std;

int cnt;
pair<int, int> p;
//탐색해야 할 위치를 알려주는 맵
int visited[2000][2000];
vector <pair<int, int>> checkkk;


pair<int, int> array[100][100] = { };
//상하좌우 검색후 찍어줘야 하는 맵
int map[2000][2000];
int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};
int gCnt;
int n, k;

void drawPoint(int dy, int dx) {
	for (int i = 0; i < 4; i++) {
		map[dy + direct[i][0]][dx + direct[i][1]] = 1;
	}
}

pair<int, int> find(pair<int, int> p) {
	int first = p.first;
	int second = p.second;
	if (array[first][second] == (0, 0)) return;
	pair<int, int> let = find(array[first][second]);
}

void uUnion(pair<int, int> now, pair<int, int> target) {
	pair<int, int> a = find(now);
	pair<int, int> b = find(target);
}

void point(int dy, int dx) {
	gCnt++;
	pair<int, int> now = { dy,dx };
	for (int i = 0; i < 4; i++) {

		int ny = dy + direct[i][0];
		int nx = dx + direct[i][1];
		pair<int, int> target = { ny, nx };

		if (ny < 0 || nx < 0 || ny >= k || nx >= k) continue;
		if (map[ny][nx] == 0) continue;

		// 인접 -> (dy,dx)와 (ny,nx)를 병합
		uUnion(now, target);
		gCnt--;
	}
}

int main() {
	cin >> n >> k;

	int dy, dx;

	//first
	for (int i = 0; i < k; i++) {
		cin >> dy >> dx;
		map[dy][dx] = 1;
		// 상하좌우 점찍기
		drawPoint(dy, dx);
	}

	while (gCnt != 1) {
		for (int y = 0; y < k; y++) {
			for (int x = 0; x < k; x++) {
				if (map[y][x] == 1) {
					point(y, x);
				}
			}
		}
		drawPoint(1, 1);
	}

	return 0;
}