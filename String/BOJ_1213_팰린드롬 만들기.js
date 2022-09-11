const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('line', function (input) {
    let dat = [];
    const len = input.length;
    for (let i = 0; i < len; i++) {
        const x = input.charCodeAt(i);
        dat[x] = dat[x] ? dat[x] + 1 : 1;
    }

    const oddItem = dat.filter((v) => v % 2 != 0);
    if (oddItem.length > 1) {
        console.log("I'm Sorry Hansoo");
        rl.close();
    }

    let front = '';
    let middle = '';
    let back = '';
    for (const key in dat) {
        let item = dat[key];
        let ch = String.fromCharCode(key);
        if (item % 2 === 1) {
            middle = ch;
            item--;
        }
        while (item > 0) {
            front += ch;
            back = ch + back;
            item -= 2;
        }
    }
    console.log(front + middle + back);
    rl.close();
}).on('close', function () {
    process.exit();
});
