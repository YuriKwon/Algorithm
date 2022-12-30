#include <iostream>
using namespace std;

int n, m;
int arr[100001];
int sum[100001]; // 누적합 값을 저장해놓는 배열

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i=1; i<=n; i++) {
    int num;
    cin >> num;
    arr[i] = arr[i-1] + num;
  }

  for (int i=0; i<m; i++) {
    int start, end;
    cin >> start >> end;
    cout << arr[end] - arr[start - 1]<< '\n';
  }

  return 0;
}
