// 순열
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, selectCnt;
int S[21][21];
int sum;
int path[20];
int answer = 21e8;

void select(int level, int cur) {
  if (level == selectCnt) {
    // 모든 쌍에 대해 합을 구하기
    // path 배열에서 이중 포문
    int abilitySum = 0;
    for (int i=0; i<selectCnt-1; i++) {
      for (int j=i+1; j<selectCnt; j++) {
        abilitySum += (S[path[i]][path[j]] + S[path[j]][path[i]]);
      }
    }

    vector<int> another = {};
    for (int i=0; i<N; i++) {
      bool isSelect = false;
      for (int j=0; j<N; j++) {
        if (i == path[j]) {
          isSelect = true;
          break;
        }
      }
      if (!isSelect) another.push_back(i);
    }

    int anotherSum = 0;

    if (another.size() == selectCnt) {
      for (int i=0; i<selectCnt-1; i++) {
        for (int j=i+1; j<selectCnt; j++) {
          anotherSum += (S[another[i]][another[j]] + S[another[j]][another[i]]);
        }
      }
      int diff = abs(anotherSum - abilitySum);

      answer = min(answer, diff);
    }

    return;
  }

  for (int i=cur; i<N; i++) {
    path[level] = i;
    select(level+1, i+1); // 순열
  }

}

int main() {
  cin >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cin >> S[i][j];
      sum += S[i][j];
    }
  }

  // N개중, N/2 개의 수 고르기!
  selectCnt = N/2;

  select(0, 0);
  cout << answer;
  return 0;
}
