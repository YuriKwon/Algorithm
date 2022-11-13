#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m, min_num;
int arr[51][51];
string s;

int main() {
	cin >> n >> m;
	for (int y=0; y<n; y++) {
		cin >> s;
		for (int x=0; x<m; x++) {
			arr[y][x] = s[x];
		}
	}
	min_num = min(n, m);
	int max_byun = 1; //조건을 만족할 때의 변의 길이 중 최대값

	for (int y=0; y<n; y++) {
		for (int x=0; x<m; x++) {
			for (int i=0; i<min_num; i++) {
				if (y+i<n && x+i<m && arr[y][x] == arr[y][x+i] && arr[y][x] == arr[y+i][x+i] && arr[y][x] == arr[y+i][x]) {
					max_byun = max(max_byun, i+1);
				}
			}
		}
	}
	cout << max_byun * max_byun;


	return 0;
}
