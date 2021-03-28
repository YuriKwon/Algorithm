#include <iostream>
#include <algorithm> // max를 위해
#include <cstring> // memcpy를 위해 
using namespace std;

int n;
int map[501][501];
int memo[500][500];
int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};
int maxi;
int maxLevel;

//int리턴이 필요(메모이제이션 때문에)
int DFS(int y, int x) {

	//DFS -> 메모이제이션 필수
	if (memo[y][x] != 0) return memo[y][x];

	int maxi = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + direct[i][0];
		int nx = x + direct[i][1];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (map[ny][nx] <= map[y][x]) continue;

		maxi = max(maxi, DFS(ny, nx));
	}
	//메모이제이션 코드 - 어려움. 복습이 필요할 듯
	memo[y][x] = maxi + 1;
	maxLevel = max(maxLevel, memo[y][x]);
	return memo[y][x];
}

int main() {

	cin >> n;

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
		}
	}
	//memcpy 주석처리하니 시간초과 안남.
	//memcpy(backup, map, sizeof(int) * n * n);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			DFS(y, x);
			//memcpy(map, backup, sizeof(int) * n * n);
		}
	}

	cout << maxLevel;
	return 0;
}

// 시간초과.. 메모이제이션이 필요하다고 한다.
// 메모이제이션 : DFS로 검색되는 경로 중, 중복 경로는 이미 이전에 구해놓은 값으로 바로 return해줘야 한다.
// 참고 링크 https://www.acmicpc.net/board/view/18025