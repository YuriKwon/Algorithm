#include <iostream>
#include <utility>
using namespace std;

int n;
int ranking = 1;
pair<int, int> arr[50];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) { // j를 1부터 하면 틀림.. 처음부터 비교해야 하니까 당연한 것!
      if (arr[i].first < arr[j].first && arr[i].second < arr[j].second) {
        ranking++;
      }
    }
    cout << ranking << ' ';
    ranking = 1;
  }
}
