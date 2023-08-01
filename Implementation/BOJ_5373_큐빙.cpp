// 코드 양이 길어지더라도 단순하게 짜는게 디버깅이 쉽다!
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int T, N;
string rotateStr;
char U[3][3], D[3][3], F[3][3], B[3][3], L[3][3], R[3][3];

void init() {
  for (int y=0; y<3; y++) {
    for (int x=0; x<3; x++) {
      U[y][x] = 'w';
      D[y][x] = 'y';
      F[y][x] = 'r';
      B[y][x] = 'o';
      L[y][x] = 'g';
      R[y][x] = 'b';
    }
  }
}

void rotateOnlyFace(char face, char dir) {
  char newFace[3][3];
  char target[3][3];
  if (face == 'U') {
    if (dir == '+') {
      for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
          newFace[x][2-y] = U[y][x];
        }
      }
    } else {
      for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
          newFace[2-x][y] = U[y][x];
        }
      }
    }

    for (int y=0; y<3; y++) {
      for (int x=0; x<3; x++) {
        U[y][x] = newFace[y][x];
      }
    }
  } else if (face == 'D') {
    if (dir == '+') {
      for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
          newFace[x][2-y] = D[y][x];
        }
      }
    } else {
      for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
          newFace[2-x][y] = D[y][x];
        }
      }
    }
    for (int y=0; y<3; y++) {
      for (int x=0; x<3; x++) {
        D[y][x] = newFace[y][x];
      }
    }
  } else if (face == 'F') {
    if (dir == '+') {
      for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
          newFace[x][2-y] = F[y][x];
        }
      }
    } else {
      for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
          newFace[2-x][y] = F[y][x];
        }
      }
    }
    for (int y=0; y<3; y++) {
      for (int x=0; x<3; x++) {
        F[y][x] = newFace[y][x];
      }
    }
  } else if (face == 'B') {
    if (dir == '+') {
      for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
          newFace[x][2-y] = B[y][x];
        }
      }
    } else {
      for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
          newFace[2-x][y] = B[y][x];
        }
      }
    }
    for (int y=0; y<3; y++) {
      for (int x=0; x<3; x++) {
        B[y][x] = newFace[y][x];
      }
    }
  } else if (face == 'L') {
    if (dir == '+') {
      for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
          newFace[x][2-y] = L[y][x];
        }
      }
    } else {
      for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
          newFace[2-x][y] = L[y][x];
        }
      }
    }
    for (int y=0; y<3; y++) {
      for (int x=0; x<3; x++) {
        L[y][x] = newFace[y][x];
      }
    }
  } else if (face == 'R') {
    if (dir == '+') {
      for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
          newFace[x][2-y] = R[y][x];
        }
      }
    } else {
      for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
          newFace[2-x][y] = R[y][x];
        }
      }
    }
    for (int y=0; y<3; y++) {
      for (int x=0; x<3; x++) {
        R[y][x] = newFace[y][x];
      }
    }
  }

}

// 시계방향만 고려
void rotateOnlySide(char face) {
  if (face == 'U') {
    char temp[3];
    for (int i=0; i<3; i++) {
      temp[i] = B[0][i];
    }
    for (int i=0; i<3; i++) {
      B[0][i] = L[0][i];
    }
    for (int i=0; i<3; i++) {
      L[0][i] = F[0][i];
    }
    for (int i=0; i<3; i++) {
      F[0][i] = R[0][i];
    }
    for (int i=0; i<3; i++) {
      R[0][i] = temp[i];
    }
  } else if (face == 'D') {
    char temp[3];
    for (int i=0; i<3; i++) {
      temp[i] = B[2][i];
    }
    for (int i=0; i<3; i++) {
      B[2][i] = R[2][i];
    }
    for (int i=0; i<3; i++) {
      R[2][i] = F[2][i];
    }
    for (int i=0; i<3; i++) {
      F[2][i] = L[2][i];
    }
    for (int i=0; i<3; i++) {
      L[2][i] = temp[i];
    }
  } else if (face == 'F') {
    char temp[3];
    for (int i=0; i<3; i++) {
      temp[i] = U[2][i];
    }
    for (int i=0; i<3; i++) {
      U[2][2-i] = L[i][2];
    }
    for (int i=0; i<3; i++) {
      L[i][2] = D[0][i];
    }
    for (int i=0; i<3; i++) {
      D[0][2-i] = R[i][0];
    }
    for (int i=0; i<3; i++) {
      R[i][0] = temp[i];
    }
  } else if (face == 'B') {
    char temp[3];
    for (int i=0; i<3; i++) {
      temp[i] = U[0][i];
    }
    for (int i=0; i<3; i++) {
      U[0][i] = R[i][2];
    }
    for (int i=0; i<3; i++) {
      R[2-i][2] = D[2][i];
    }
    for (int i=0; i<3; i++) {
      D[2][i] = L[i][0];
    }
    for (int i=0; i<3; i++) {
      L[2-i][0] = temp[i];
    }
  } else if (face == 'L') {
    char temp[3];
    for (int i=0; i<3; i++) {
      temp[i] = U[i][0];
    }
    for (int i=0; i<3; i++) {
      U[2-i][0] = B[i][2];
    }
    for (int i=0; i<3; i++) {
      B[2-i][2] = D[i][0];
    }
    for (int i=0; i<3; i++) {
      D[i][0] = F[i][0];
    }
    for (int i=0; i<3; i++) {
      F[i][0] = temp[i];
    }
  } else if (face == 'R') {
    char temp[3];
    for (int i=0; i<3; i++) {
      temp[i] = U[i][2];
    }
    for (int i=0; i<3; i++) {
      U[i][2] = F[i][2];
    }
    for (int i=0; i<3; i++) {
      F[i][2] = D[i][2];
    }
    for (int i=0; i<3; i++) {
      D[2-i][2] = B[i][0];
    }
    for (int i=0; i<3; i++) {
      B[2-i][0] = temp[i];
    }
  }
}

void rotate(string s) {
  char rotateFace = s[0];
  char rotateDir = s[1];

  rotateOnlyFace(rotateFace, rotateDir);
  rotateOnlySide(rotateFace);
  if (rotateDir == '-') {
    rotateOnlySide(rotateFace);
    rotateOnlySide(rotateFace);
  }
}

int main() {
  cin >> T;
  for (int t=0; t<T; t++) {
    init();

    cin >> N;
    for (int n=0; n<N; n++) {
      cin >> rotateStr;
      rotate(rotateStr);
      // test();
    }
    // print();

    for (int y=0; y<3; y++) {
      for (int x=0; x<3; x++) {
        cout << U[y][x];
      }
      cout << '\n';
    }
  }

  return 0;
}
