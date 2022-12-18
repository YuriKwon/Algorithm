function solution(rows, columns, queries) {
  let answer = [];
  let cnt = 1;
  const arr = new Array(rows + 1).fill(0).map(() => new Array(columns + 1));

  for (let i = 1; i <= rows; i++) {
    for (let j = 1; j <= columns; j++) {
      arr[i][j] = cnt++;
    }
  }

  queries.forEach((query) => {
    let changedPositionNum = []; // 위치 이동에 의해 자리가 바뀐 숫자들
    const rotateStartPointVal = arr[query[0]][query[1]];
    const startY = query[0];
    const startX = query[1];
    const endY = query[2];
    const endX = query[3];

    const width = endX - startX;
    const height = endY - startY;

    for (let i = 0; i < height; i++) {
      const newValue = arr[startY + i + 1][startX];
      changedPositionNum.push(newValue);
      arr[startY + i][startX] = newValue;
    }

    for (let i = 0; i < width; i++) {
      const newValue = arr[endY][startX + i + 1];
      changedPositionNum.push(newValue);

      arr[endY][startX + i] = newValue;
    }

    for (let i = 0; i < height; i++) {
      const newValue = arr[endY - i - 1][endX];
      changedPositionNum.push(newValue);

      arr[endY - i][endX] = newValue;
    }

    for (let i = 0; i < width - 1; i++) {
      const newValue = arr[startY][endX - i - 1];
      changedPositionNum.push(newValue);

      arr[startY][endX - i] = newValue;
    }

    changedPositionNum.push(rotateStartPointVal);
    arr[startY][startX + 1] = rotateStartPointVal;

    answer.push(Math.min(...changedPositionNum));
    changedPositionNum = [];
  });

  return answer;
}

// solution(6, 6, [
//   [2, 2, 5, 4],
//   [3, 3, 6, 6],
//   [5, 1, 6, 3]
// ]);
