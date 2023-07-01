#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string sliceTree(string s, int a, int b) {
    return s.substr(a, b-a); // a ~ b까지 
}

void printPostOrder(string preorder, string inorder) {
    // 트리에 포함된 노드의 수
    int n = preorder.length();
    // 재귀 종료 조건 -> 반드시 필요
    if (n == 0) return;

    // 루트: 전위 탐색 결과로 바로 알 수 있음
    char root = preorder[0];
    // 왼쪽 서브트리의 크기: inorder에서 루트의 위치를 찾으면 알 수 있음
    int sizeL = inorder.find(root);
    // 오른쪽 서브트리의 크기도 알 수 있음
    int sizeR = n - sizeL - 1;

    // postorder 결과 출력: 왼쪽 서브트리 -> 오른쪽 서브트리 -> 루트 (재귀적으로 탐색 후 출력)
    printPostOrder(sliceTree(preorder, 1, 1 + sizeL), sliceTree(inorder, 0, sizeL));
    printPostOrder(sliceTree(preorder, 1 + sizeL, n), sliceTree(inorder, 1 + sizeL, n));
    cout << root;
}

int main() {
    // 테스트 케이스 개수 미정(입력이 안들어올 때까지)
    string input;
    
    while(true) {
        string preorder, inorder;
        cin >> preorder >> inorder;

        if (!preorder.length()) break;

        printPostOrder(preorder, inorder);
        cout << "\n";
    }

    
    return 0;
}