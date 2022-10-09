const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', function (n) {
    let hansuCnt = 0;

    for (let i = 1; i <= +n; i++) {
        const str = '' + i;
        const len = str.length;
        if (len === 1) hansuCnt++;
        else {
            let diff = 0;
            let isHansu = true;
            for (let j = 0; j < len - 1; j++) {
                if (j === 0) diff = str[j + 1] - str[j];
                else {
                    if (diff !== str[j + 1] - str[j]) {
                        isHansu = false;
                        break;
                    } else {
                        diff = str[j + 1] - str[j];
                    }
                }
            }
            if (isHansu) hansuCnt++;
        }
    }
    console.log(hansuCnt);
    rl.close();
}).on('close', function () {
    process.exit();
});
