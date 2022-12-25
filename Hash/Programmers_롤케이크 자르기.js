function solution(topping) {
  let answer = 0;
  let leftPieceTopping = new Map();
  let rightPieceTopping = new Map();

  // 처음에 다 오른쪽 조각에 토핑 넣어놓기
  topping.forEach((item) => {
    if (rightPieceTopping.has(item)) {
      rightPieceTopping.set(item, rightPieceTopping.get(item) + 1);
    } else {
      rightPieceTopping.set(item, 1);
    }
  });

  // 한칸씩 쪼개면서 토핑 종류 개수 비교
  const toppingCnt = topping.length;
  for (let i = 0; i < toppingCnt - 1; i++) {
    const item = topping[i];
    
    // 왼쪽 조각에 현재 자른 부분 추가
    if (leftPieceTopping.has(item)) {
      leftPieceTopping.set(item, leftPieceTopping.get(item) + 1);
    } else {
      leftPieceTopping.set(item, 1);
    }

    // 오른쪽 조각에 현재 자른 부분 빼기
    if (rightPieceTopping.get(item) === 1) {
      rightPieceTopping.delete(item);
    } else {
      rightPieceTopping.set(item, rightPieceTopping.get(item) - 1);
    }

    if (leftPieceTopping.size === rightPieceTopping.size) {
      answer++;
    }
  }

  return answer;
}
