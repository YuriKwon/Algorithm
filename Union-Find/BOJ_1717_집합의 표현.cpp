#include <iostream>
using namespace std;

int parent[2000000];

int find(int a) {
    //계속 틀린이유 : 0도 입력값이기 때문에 0이 아닌 -1이 parent 초기값이 되어야 하는 걸 간과함
	if (parent[a] == -1) return a;
	int let = find(parent[a]);
	parent[a] = let;
	return let;
}

void setGroup(int a, int b) {
	int bossA = find(a);
	int bossB = find(b);
	if (bossA == bossB) return;
	parent[bossB] = bossA;
}

int main() {
    //시간 초과 해결을 위한 코드
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
    //parent 배열 -1로 초기화 (n+1개 만큼)
	fill_n(parent, n + 1, -1);
	int op, num1, num2;
	for (int i = 0; i < m; i++) {
		cin >> op >> num1 >> num2;
		if (op == 0) {
			setGroup(num1, num2);
		}
		else {
			int a = find(num1);
			int b = find(num2);
            //endl보다 '\n'이 더 빠름
			if (a == b) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}

	return 0;
}