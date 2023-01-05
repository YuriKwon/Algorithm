#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
long long answer;
vector<long long> position; // 집의 좌표

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> c;
  for (int i=0; i<n; i++) {
    long long pos;
    cin >> pos;
    position.push_back(pos);
  }
  sort(position.begin(), position.end());

  // 설치할 공유기 간의 거리로 이분 탐색 예정,
  // 시작점: 최소거리(1)
  // 끝점: 최대거리(마지막 집 위치 - 처음 집 위치)
  long long start = 1;
  long long end = position[n-1] - position[0];

  while(start <= end) {
    long long mid = (start + end) / 2; // 집 사이의 거리
    int cnt = 1; // 설치한 공유기 개수
    int prev = position[0]; // 이전 집

    for (int i=1; i<n; i++) {
      // mid보다 집 간격이 넓으면, 공유기 설치
      if (position[i] - prev >= mid) {
        cnt++;
        prev = position[i];
      }
    }

    // 공유기를 c값보다 많이 설치한 경우, 설치 간격 늘리기
    if (cnt >= c) {
      answer = max(answer, mid);
      start = mid + 1;
    }
    // 공유기를 c값보다 적게 설치한 경우, 설치 간격 좁히기
    else {
      end = mid - 1;
    }
  }

  cout << answer;
  return 0;
}

// 알고리즘 배운 블로그: https://katfun.tistory.com/entry/%EB%B0%B1%EC%A4%80-2110%EB%B2%88-%EA%B3%B5%EC%9C%A0%EA%B8%B0-%EC%84%A4%EC%B9%98
// 확실히 어려워서, 추후 복습 필요
