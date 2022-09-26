let num;
let prob = []; // e w s n // 각 방향 확률
let simplePathProbability = 0; // 단순경로 확률

// init array
let arr = new Array(30).fill(0).map(() => new Array(30));
for (var y = 0; y < 30; y++) {
    for (var x = 0; x < 30; x++) {
        arr[y][x] = 0;
    }
}

const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', function (input) {
    let inputArr = input.split(' ');
    num = inputArr[0];
    prob[0] = inputArr[1] / 100;
    prob[1] = inputArr[2] / 100;
    prob[2] = inputArr[3] / 100;
    prob[3] = inputArr[4] / 100;
    arr[15][15] = 1;
    dfs(0, 1, 15, 15);
    console.log(simplePathProbability);
    rl.close();
}).on('close', function () {
    process.exit();
});

// accumulator: 확률(누적곱) - reduce 같은..
function dfs(level, accumulator, y, x) {
    if (arr[y][x] > 1) return; // 단순경로가 아니면 리턴
    if (accumulator === 0) return;
    if (level == num) {
        simplePathProbability += accumulator;
        return;
    }

    let directionX = [1, -1, 0, 0];
    let directionY = [0, 0, 1, -1];
    for (let i = 0; i < 4; i++) {
        // 해당 방향으로 이동할 확률이 0이 아니면, 이동
        // if (prob[i] != 0) {
        let ny = y + directionY[i];
        let nx = x + directionX[i];
        arr[ny][nx]++;
        // 여기서 다음 좌표에다가 체크
        dfs(level + 1, accumulator * prob[i], ny, nx);
        // 여기서 이전 좌표 해제
        arr[ny][nx]--;
        // }
    }
}
