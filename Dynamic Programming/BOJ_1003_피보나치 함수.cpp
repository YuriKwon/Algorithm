#include <iostream>
using namespace std;

int T, N;
int zero[41] = {1, 0, };
int one[41] = {0, 1, };

int main() {
  cin >> T;
  for (int t=0; t<T; t++) {
    cin >> N;
    for (int i=2; i<=N; i++) {
      zero[i] = zero[i-1] + zero[i-2];
      one[i] = one[i-1] + one[i-2];
    }
    cout << zero[N] << " " << one[N] << "\n";
  }
  return 0;
}
