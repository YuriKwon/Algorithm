#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;


//priority queue 우선순위 큐(힙)

int main() {
	int n;
	cin >> n;
	int num;

    //최소힙을 만들기 위해 greater<int> 로 정렬기준 설정
	priority_queue<int, vector<int>, greater<int>> pq;

    //시간 초과 해결 : C와 C++의 표준 stream의 동기화를 끊는 역할
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			//pq의 사이즈가 가득 찼으면, 최솟값을 빼고 새로운 값을 넣어줌 -> 시간초과
			//push부터하고 pop을 해야 에러가 나지 않는다..(예 :  -9 - 6 -3 / - 8 - 5 - 2 / - 7 - 4 - 1)
			//부등호는 =에서 >로 바꿔야 함..
			pq.push(num);
			if (pq.size() >n) pq.pop();
		}
	}
	//pq 중 최솟값 출력
	cout << pq.top();
	return 0;
}