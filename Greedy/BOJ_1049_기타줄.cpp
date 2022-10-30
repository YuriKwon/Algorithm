#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int minPackPrice = 1000;
int minPiecePrice = 1000;

int main() {
  cin >> n >> m;
  int packNum = n / 6;
  int pieceNum = n % 6;

  for (int i=0; i<m; i++) {
    int p1, p2;
    cin >> p1 >> p2;
    if (p1 < minPackPrice) minPackPrice = p1;
    if (p2 < minPiecePrice) minPiecePrice = p2;
  }

  int packagePrice1 = packNum * minPackPrice;
  int packagePrice2 = packNum * 6 * minPiecePrice;
  int piecePrice = pieceNum * minPiecePrice;

  cout << min(packagePrice1, packagePrice2) + min(piecePrice, minPackPrice);
  return 0;
}
