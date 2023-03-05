#include <iostream>
#include <string>
using namespace std;

int m;
string cmd;
int cmdNum;
int arr[21];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> m;
  
  // string은 switch문 사용 불가
  for (int i = 1; i <= m; i++) {
    cin >> cmd;
    if (cmd == "add") {
      cin >> cmdNum;
      arr[cmdNum] = 1;
    } else if (cmd == "check") {
      cin >> cmdNum;
      if (arr[cmdNum] == 1) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    } else if (cmd == "remove") {
        cin >> cmdNum;
        arr[cmdNum] = 0;
    } else if (cmd == "toggle") {
      cin >> cmdNum;
      if (arr[cmdNum] == 1) {
        arr[cmdNum] = 0;
      } else {
        arr[cmdNum] = 1;
      }
    } else if (cmd == "all") {
      for (int i = 1; i <= 20; i++) {
          arr[i] = 1;
        }
    } else if (cmd == "empty") {
      for (int i = 1; i <= 20; i++) {
          arr[i] = 0;
      }
    }
  }
  return 0;
}
