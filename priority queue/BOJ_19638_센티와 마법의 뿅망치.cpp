#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long int n, h, t, cnt;
priority_queue<long long int> pq; // 거인 키가 들어있는 우선순위 큐

int main() {

	cin >> n >> h >> t;
	for (int i = 0; i < n; i++) {
		long long int num;
		cin >> num;
		pq.push(num);
	}

	for (int i = 0; i < t; i++) {
		long long int top = pq.top(); // 가장 큰 거인의 키.
		if (top <= 1) break;
		if (top < h) break;
		
		// top >= h
		top = top / 2; // 문제에 키가 "반드시" 정수라는 조건이 없어서 혼란의 여지가 있음. 
		pq.pop();
		pq.push(top);
		cnt++;
	} 
	if (pq.top() < h) {
		cout << "YES" << '\n' << cnt;
	}
	else {
		cout << "NO" << '\n' << pq.top();
	}
	return 0;
}