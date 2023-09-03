#include <string>
#include <vector>

using namespace std;
struct Node{
    int width;
    int height;
};

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int allTileCnt = brown + yellow;
    for (int i=2; i<allTileCnt; i++) {
        // i는 세로길이
        if (allTileCnt % i != 0) continue;

        int h = i; // 세로
        int w = allTileCnt / h; // 가로
        if (h > w) break;

        int brownTileCnt = (2*h + 2*w) - 4;
        if (brownTileCnt == brown) {
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }

    return answer;
}
