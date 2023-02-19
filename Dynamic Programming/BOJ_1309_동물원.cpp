#include <iostream>
using namespace std;

int n;
int arr[100002];

int main() {
  cin >> n;
  
  // 초기값
  arr[1] = 3;
  arr[2] = 7;

  int num = 3;
  while(num <= n) {
    arr[num] = (arr[num - 1] * 2 + arr[num - 2])% 9901;
    num++;
  }

  cout << arr[n];

  return 0;
}
