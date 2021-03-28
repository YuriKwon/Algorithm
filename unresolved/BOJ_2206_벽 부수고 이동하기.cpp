#include <iostream>
#include <algorithm>
#include <cstring> //for memset
#include <string>
using namespace std;

//답은 나오는데 시간초과가 뜸
//해결법 : used를 3중배열로 만들어서 벽을 부순적이 있는지, 없는지까지 체크해줘야 함.
//관련 설명 : https://www.acmicpc.net/board/view/27386

int n, m;
int map[1000][1000];
int used[1000][1000]; 
struct Node {
	int y, x, lev;
};
Node war[1000000];
Node queue[1000000];
int head, tail;
int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1
};

int BFS() {
	//시작점 : (0,0)
	//끝점 : (n-1, m-1)
	head = 0;
	tail = 0;
	memset(used, 0, 1000000 * sizeof(int));
	queue[tail++] = { 0,0,1 };
	used[0][0] = 1;
	while (head != tail) {
		Node now = queue[head++];
		for (int i = 0; i < 4; i++) {
			int ny = now.y + direct[i][0];
			int nx = now.x + direct[i][1];

			if (ny == n - 1 && nx == m - 1) return now.lev;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (map[ny][nx] == 1) {
				continue;
			}
			if (used[ny][nx] == 1) continue;

			queue[tail++] = { ny, nx, now.lev + 1 };
			used[ny][nx] = 1;
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	int num=0; //벽의 개수
	int mini=999; //최단거리
	int flag = -1; // 경로를 못찾았을 경우 -1
	for (int y = 0; y < n; y++) {
		string s;
		cin >> s;
		for (int x = 0; x < m; x++) {
			map[y][x] = (int)(s[x]-'0');
			//벽 좌표 전부 war(기능:큐)에 넣어주기
			if (map[y][x] == 1) {
				war[tail++] = { y,x };
				num++;
			}
		}
	}


	//1. 벽 뚫지 않고 최단거리 선택 & 최단거리 갱신
	int ret = BFS();
	if (ret != -1) {
		mini = min(mini, ret);
		flag = 0;
	}

	//2. 벽 하나 뚫은 후 최단거리 선택
	// 모든 벽을 뚫으면 시간초과임.
	// 관련 질문 : https://www.acmicpc.net/board/view/38750
	for (int i = 0; i < num; i++) {
		Node now = war[i]; //벽선택
		map[now.y][now.x] = 0; //벽 없애주기
		int ret2 = BFS();
		if (ret2 != -1) {
			mini = min(mini, ret2);
			flag = 0;
		}
		map[now.y][now.x] = 1; //벽 원상복구
	}

	if (flag == -1) cout << -1;
	else cout << mini+1; //시작칸도 포함해서 셈

	return 0;
}