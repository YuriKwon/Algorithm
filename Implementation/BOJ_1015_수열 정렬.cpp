#include <iostream>
using namespace std;

int n;
int a[51];
int answer[51];
int minValue = 1000;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < minValue) minValue = a[i];
  }

  int order = 0;
  while(order < n) {
    for (int i=0; i<n; i++) {
      if (a[i] == minValue) {
        answer[i] = order;
        order++;
      }
      if (i == n-1) {
        minValue++;
      }
    }
  }

  for (int i=0; i<n; i++) {
    cout << answer[i] << " ";
  }

  return 0;
}
