#include <iostream>
using namespace std;

int main() {

	int price;
	cin >> price;
	int changes = 1000 - price;

	int vect[6] = { 500, 100, 50, 10, 5,1 };
	int cnt = 0; //거스름돈 개수

	//규칙 : 큰 동전부터
	for (int i = 0; i < 6; i++) {
		cnt += changes / vect[i];
		changes %= vect[i];
	}
	cout << cnt;
	return 0;
}