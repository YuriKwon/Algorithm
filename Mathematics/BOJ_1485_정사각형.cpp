#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int t, n1, n2;
struct Node {
	int y,x;
};

Node arr[4];

// 편의상 sqrt 생략
int getDistance(Node a, Node b) {
	return (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i=0; i<t; i++) {
		priority_queue<int> pq;
		for (int j=0; j<4; j++) {
			cin >> n1 >> n2;
			arr[j].y = n1;
			arr[j].x = n2;
		}

		for (int j=0; j<3; j++) {
			for (int k=j+1; k<4; k++) {
				pq.push(getDistance(arr[j], arr[k]));
			}
		}
		int arr[6];
		int idx = 0;
		while(!pq.empty()) {
			arr[idx] = pq.top();
			pq.pop();
			idx++;
		}
		if ((arr[0] != arr[1]) || (arr[1] == arr[2]) || (arr[2] != arr[3])|| (arr[3] != arr[4]) || (arr[4] != arr[5])) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
	}


	return 0;
}
