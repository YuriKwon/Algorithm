function solution(s) {
  const len = s.length;
  let minLen = Number.MAX_SAFE_INTEGER; // 압축 후 최소 길이
  let isCompressed = false;

  // i: 압축할 문자열의 길이
  for (let compressLen = 1; compressLen <= len / 2; compressLen++) {
    let idx = 0; // 문자열 자를 시작점
    let compressStrArr = []; // 자른 문자열을 넣어놓는 배열
    let compressStr = '';

    while (idx <= len - 1) {
      compressStrArr.push(s.substring(idx, idx + compressLen));
      idx += compressLen;
    }

    // 압축
    let compressStrLen = compressStrArr.length;
    let prevStr = '';
    let currentCompressCnt = 1; // 현재 문자열로 압축된 횟수
    for (let i = 0; i < compressStrLen; i++) {
      isCompressed = true;

      if (prevStr === '') {
        prevStr = compressStrArr[i];
        continue;
      }
      if (compressStrArr[i].length !== prevStr.length) {
        compressStr += (currentCompressCnt > 1 ? String(currentCompressCnt) : '') + compressStrArr[i - 1];
        // 현재 위치
        currentCompressCnt = 1;
        compressStr += (currentCompressCnt > 1 ? String(currentCompressCnt) : '') + compressStrArr[i];
        continue;
      }
      // 압축 O
      if (prevStr === compressStrArr[i]) {
        currentCompressCnt++;
        if (i === compressStrLen - 1) {
          compressStr += String(currentCompressCnt) + compressStrArr[i - 1];
        }

        // 이전 압축과 동일한 문자열로 압축했는지
        if (i > 1) {
          if (compressStrArr[i] === compressStrArr[i - 2]) {
          }
        }
      }
      // 압축 X
      else {
        compressStr += (currentCompressCnt > 1 ? String(currentCompressCnt) : '') + compressStrArr[i - 1];
        currentCompressCnt = 1;

        if (i === compressStrLen - 1) {
          compressStr += (currentCompressCnt > 1 ? String(currentCompressCnt) : '') + compressStrArr[i];
        }
      }
      prevStr = compressStrArr[i];
    }
    minLen = Math.min(compressStr.length, minLen);
  }
  return isCompressed ? minLen : 1;
}
