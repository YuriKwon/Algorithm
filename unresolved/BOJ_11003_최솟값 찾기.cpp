#include <iostream>
#include <queue>
#include <deque>
using namespace std;

/*
pq compare 함수 작성하려고 쓴 부분
struct Node {
	int a;
};
typedef struct Node Node;

struct compare {
	bool operator()(Node& v, Node& tar) {
		if (v.a >= 0 && tar.a >= 0) return v.a > tar.a;
		//기준값이 양수고 다른애가 음수면 기준값 리턴
		else if (v.a <= 0 && tar.a >= 0) return true;
		//기준값이 음수면 false를 리턴(=다른애를 리턴)
		else if (v.a >= 0 && tar.a <= 0) return false;
		else if (v.a <= 0 && tar.a <= 0) {
			//2^10으로 가면 int를 못쓰기때문에 2를 붙임
			v.a = 2000000000;
			tar.a = 2000000000;
			return true;
		}
	}
};

//priority_queue<Node, vector<Node>, compare> pq;

//tar(기준값)이 우선순위가 높은 기준을 충족하면 true리턴
// < 연산자 오버로딩? (더 공부 필요)

priority_queue<int> pq;
*/

int main() {
	//Node I;
	int n, l;
	cin >> n >> l;
	int num;

	
	for (int i = 0; i < n; i++) {
		if (i < n - 1) {
			cin >> num;
			//pq.push(num);
			//cout << pq.top();
		}
		else {
			//cout << pq.top();
			//.. 생각해보니까 여기서 start index값을 못뺀다...pq니까.......pq로 풀면 안될 듯 하다(덱으로 돌리자)
		}
	}

	return 0;
}