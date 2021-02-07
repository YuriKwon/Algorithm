#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

//이중 for문 -> 시간초과 발생(O(n^2), n 최대 10,000이므로 최대 반복횟수 1억번(=1초 소요)인데 시간제한 0.5초)
//따라서, 투 포인터로 풀어야 한다.
int main() {
	int n, m;
	cin >> n >> m;
	vector <int> v;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	int start = 0;
	int end = 0;
	int cnt = 0;

	int ret = v[start]; //구간합
	while (1) {
        //너무 case를 일일히 나눈 것 같다. 더 효율적인 풀이법이 있을 듯.

        //구간합 == m 이면 카운트 증가
		if (ret == m) cnt++;

        //start, end 커서 모두 끝에 도달시 반복문 종료
		if (start == n-1 && end == n-1) break;

        //end커서가 끝에 도달시, start커서만 옮겨준다. end커서 증가시키면 참조 에러이므로 continue 필요
		if (end == n-1) {
			ret -= v[start];
			start++;
			continue;
		}

		if (ret < m) {
			end++;
			//if (end == n) continue;
			ret += v[end];
		}

		else if (ret == m) {
			ret -= v[start];
			start++;
		}
        
		else if (ret > m) {
			ret -= v[start];
			start++;
		}
	}
	cout << cnt;
	return 0;
}