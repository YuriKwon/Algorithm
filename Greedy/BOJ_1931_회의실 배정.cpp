#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int start;
	int end;
};

//n 조건 잘보기 : 처음에 별 생각없이 arr을 100개로 잡았다가 런타임에러가 났음
Node arr[100000];

int compare(Node a, Node b) {
	/*
	* 우선순위 조건
	* 1. 회의가 끝나는 시간이 빠른 것
	* 2. 회의가 시작하는 시간이 빠른 것
	*/
	if (a.end < b.end) return 1;
	if (a.end > b.end) return 0;
	return a.start < b.start;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].start >> arr[i].end;
	}

	sort(arr, arr + n, compare);

	//다음 회의 시작 가능 시간
	int startTime = 0;
	//회의 수
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i].start >= startTime) {
			startTime = arr[i].end;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}