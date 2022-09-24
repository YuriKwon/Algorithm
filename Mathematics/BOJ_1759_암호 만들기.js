// 관련 개념: 조합
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];
rl.on('line', function (line) {
    input.push(line);
    // 두 줄 입력받기
    if (input.length === 2) rl.close();
}).on('close', function () {
    // console.log(input);
    main();
    process.exit();
});

function main() {
    let firstLine = input[0].split(' ');
    let secondLine = input[1].split(' ');
    let l = firstLine[0];
    let c = firstLine[1];
    let alphabet = secondLine.sort();
    let result = filter(getCombinations(alphabet, +l));
    result.forEach((item) => console.log(item));
}

// 조합
function getCombinations(arr, selectNumber) {
    let result = [];
    if (selectNumber === 1) return arr.map((value) => [value]);

    // sort 이유: AW, WA가 따로 카운팅 되는 것 방지
    [...arr].sort().forEach((item, index, originArr) => {
        const rest = originArr.slice(index + 1);
        const combinations = getCombinations(rest, selectNumber - 1);
        const attached = combinations.map((combination) => item + combination);
        result.push(...attached);
    });
    return result;
}

function filter(result) {
    let vowel = ['a', 'e', 'i', 'o', 'u'];

    return result.filter((item) => {
        let vowelCnt = 0; // 모음 개수
        let foundVowel = false;
        for (const ch of item) {
            // console.log(ch);
            for (const v of vowel) {
                if (ch === v) {
                    foundVowel = true;
                    vowelCnt++;
                }
            }
        }

        let consonantCnt = item.length - vowelCnt; // 자음 개수
        if (vowelCnt === 0) return false;
        if (consonantCnt < 2) return false;
        return true;
    });
}
