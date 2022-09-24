// 관련 개념: 조합
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
let input = [];

rl.on('line', function (line) {
    input.push(line);
    // 세 줄 입력받기
    if (input.length === 3) rl.close();
}).on('close', function () {
    let result = main();
    console.log(result);
    process.exit();
});

function main() {
    let startCoordinate = input[0].split(' ');
    let middleCoordinate = input[1].split(' ');
    let endCoordinate = input[2].split(' ');
    let startX = startCoordinate[0];
    let startY = startCoordinate[1];
    let middleX = middleCoordinate[0];
    let middleY = middleCoordinate[1];
    let endX = endCoordinate[0];
    let endY = endCoordinate[1];

    // ccw 공식
    let ccw = startX * middleY + middleX * endY + endX * startY - (middleX * startY + endX * middleY + startX * endY);
    if (ccw > 0) return 1;
    else if (ccw < 0) return -1;
    else return ccw;
}
