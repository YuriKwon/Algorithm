#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int height[201]; // key: weight(몸무게)
vector<int> weight;
int ranking = 1; // 순위
vector<int> order; // 들어온 순서
int answer[201];

int main() {
  cin >> n;

  for (int i=0; i<n; i++) {
    int w, h;
    cin >> w >> h;
    height[w] = h;
    weight.push_back(w);
    order.push_back(w);
  }
  sort(weight.begin(), weight.end(), greater<int>());

  for (int i=0; i<n; i++) {
    // cout << weight[i] << ' ';
    // cout << height[weight[i]] << endl;
    if (i == n-1) {
      answer[weight[i]] = ranking;
      break;
    }
    if (height[weight[i]] > height[weight[i+1]]) {
      answer[weight[i]] = ranking;
      ranking = i + 2;
    } else if (height[weight[i]] <= height[weight[i+1]]){
      answer[weight[i]] = ranking;
    }
  }

  for (int i=0; i<n; i++) {
    cout << answer[order[i]] << ' ';
  }

  return 0;
}
