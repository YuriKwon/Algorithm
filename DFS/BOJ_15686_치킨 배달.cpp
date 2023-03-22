#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, num, chickenShopCnt;
int houseArr[51][51]; // 집의 위치만 찍은 배열
struct Node{
  int y, x;
};
vector<Node> chickenShop; // 전체 치킨집 위치
vector<Node> selectedChickenShop; // 선택된 치킨집 위치
Node visited[13]; // 방문한 치킨집
int minChickenDistance = 99999; // 치킨거리의 합 최소

// 현재 선택된 치킨집 기준으로, 치킨거리의 합 구하기
int getSumChickenDistance() {
  int sumChickenDistance = 0;
  for (int y=0; y<n; y++) {
    for (int x=0; x<n; x++) {
      int distance = 99999; // 치킨거리
      if (houseArr[y][x] == 1) { // 각 집에서의 치킨 거리 중 최소값으로 distance 갱신
        for (int i=0; i<m; i++) {
          distance = min(distance, abs(selectedChickenShop[i].y - y) + abs(selectedChickenShop[i].x - x));
        }
        sumChickenDistance += distance;
      }
    }
  }
  return sumChickenDistance;
}

void DFS(int level, int next) { // next: 치킨집 선택 시 조합 개념 적용을 위해 필요
  if (level == m) { // 치킨집 m개 선택 완료
    for (int i=0; i<m; i++) { // 선택된 치킨집을 벡터에 저장
      selectedChickenShop.push_back({visited[i].y, visited[i].x});
    }

    // 현재 선택된 치킨집 기준으로, 치킨거리의 합 구하기 & 최소 치킨거리 갱신
    minChickenDistance = min(minChickenDistance, getSumChickenDistance());
    selectedChickenShop.clear();
  }

  for (int i=next; i<chickenShopCnt; i++) {
    visited[level] = chickenShop[i];
    DFS(level+1, i+1);
    visited[level] = {-1, -1};
  }
}

int main() {
  cin >> n >> m;
  for (int y=0; y<n; y++) {
    for (int x=0; x<n; x++) {
      cin >> num;
      if (num != 2) houseArr[y][x] = num; // 집만 저장
      else chickenShop.push_back({y, x}); // 치킨집은 벡터에 저장
    }
  }
  chickenShopCnt = chickenShop.size();

  // 치킨집 M개 선택
  DFS(0, 0);

  cout << minChickenDistance;

  return 0;
}
