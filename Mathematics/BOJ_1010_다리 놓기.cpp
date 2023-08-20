#include <iostream>
using namespace std;

long long  T, N, M;

int main() {
  cin >> T;
  for (int t=0; t<T; t++) {
    int res = 1, tmp = 1;
    cin >> N >> M;

    for (int i = M; i > M - N; --i) {
        res = res * i;
        res = res / tmp++;
      }
    cout << res << endl;
  }

  return 0;
}
