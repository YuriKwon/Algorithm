function solution(n, info) {
    let maxDiff = 0;
    let rInfo = Array(11).fill(0);

    // count: 라이언이 쏜 화살 개수
    const dfs = (aScore, rScore, count, idx, board) => {
        if (count > n) return;
        if (idx > 10) {
            let diff = rScore - aScore;
            if (diff > maxDiff) {
                board[10] = n - count; // board[10]: 쏠 수 있는 화살 개수
                maxDiff = diff;
                rInfo = board;
            }
            return;
        }
        if (count < n) {
            let board2 = [...board];
            board2[10 - idx] = info[10 -idx] + 1;
            dfs(aScore, rScore + idx, count + info[10 - idx] + 1, idx + 1, board2);
        }

        if (info[10 -idx] > 0) {
            dfs(aScore + idx, rScore, count, idx + 1, board);
        } else {
            dfs(aScore, rScore, count, idx + 1, board);
        }
    }
    dfs(0, 0, 0, 0, rInfo);

    if (maxDiff <= 0) return [-1];
    else return rInfo;

}

// 어렵,, dfs 함수 다시 짜보기
