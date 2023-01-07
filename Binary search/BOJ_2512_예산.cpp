#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long m;
long long answer;
vector<long long> budgets;

int assignMoney(long long upperLimit) {
  long long sum = 0; // 배정액
  for (int i=0; i<n; i++) {
    if (budgets[i] <= upperLimit) {
      sum += budgets[i];
    } else {
      sum += upperLimit;
    }
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;

  for (int i=0; i<n; i++) {
    long long budget;
    cin >> budget;
    budgets.push_back(budget);
  }
  cin >> m;

  sort(budgets.begin(), budgets.end());
  long long left = 1;
  long long right = budgets[n - 1];

  while(left <= right) {
    long long mid = (left + right) / 2; // upperLimit
    long long sum = assignMoney(mid);

    if (sum <= m) {
      left = mid + 1;
      answer = mid;
    }
    else {
      right = mid - 1;

    }
  }

  cout << answer;
  return 0;
}
