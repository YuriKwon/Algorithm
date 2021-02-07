#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdlib> //abs 사용하기 위해 선언
using namespace std;

//절댓값, 원래값 둘다 저장해야 함 -> pair에 저장한다.
//정렬은 절댓값 기준이므로 절댓값을 first에 넣는다.
typedef pair <int, int> p;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int num;
    
	priority_queue<p, vector<p>, greater<p>> pq;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
			if (!pq.empty()) {
				cout << pq.top().second << endl;
				pq.pop();
			}
			else cout << '0' << endl;
		}
		else {
			pq.push({ abs(num), num });
		}
	}
	return 0;
 }