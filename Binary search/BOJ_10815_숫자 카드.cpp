#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int cards[500000];
int nums[500000];


int isInCards(int num) {
  int left = 0;
  int right = n-1;
  while(left <= right) {
    int mid = (left + right) / 2;

    if (num == cards[mid]) return 1;
    else if (num > cards[mid]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return 0;
}

int main() {
  // fast I/O 안쓰면 시간 초과
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i=0; i<n; i++) {
    int num;
    cin >> num;
    cards[i] = num;
  }
  sort(cards, cards + n);

  cin >> m;
  for (int i=0; i<m; i++) {
    int num;
    cin >> num;
    cout << isInCards(num) << " ";
  }
}
